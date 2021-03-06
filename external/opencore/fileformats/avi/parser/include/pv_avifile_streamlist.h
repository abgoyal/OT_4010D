
#ifndef PV_AVIFILE_STREAMLIST_H_INCLUDED
#define PV_AVIFILE_STREAMLIST_H_INCLUDED

#ifndef PV_AVIFILE_TYPEDEFS_H_INCLUDED
#include "pv_avifile_typedefs.h"
#endif

#ifndef PV_AVIFILE_PARSER_UTILS_H_INCLUDED
#include "pv_avifile_parser_utils.h"
#endif


//structure to store stream format specific information
class PVAviFileStreamFormatStruct
{

    public:
        //constructor
        PVAviFileStreamFormatStruct()
        {
            iType = UNKNOWN;
        }

        //destructor
        ~PVAviFileStreamFormatStruct()
        {
            iType = UNKNOWN;
        }

        //Depending on stream type, either iVidBitMapInfo or iAudWaveFormatEx will be valid.
        StreamType                  iType;

        union
        {
            BitMapInfoStruct    iVidBitMapInfo;     //Video Format Info
            WaveFormatExStruct  iAudWaveFormatEx;   //Audio Format Info
        };
};



//class to parse stream list that contains stream specificinformation
class PVAviFileStreamlist: public PVAviFileParserStatus
{

    public:

        //constructor
        PVAviFileStreamlist(PVFile *aFp, uint32 aStrListSz);

        //destructor
        ~PVAviFileStreamlist() {};

        //methods to retrieve PVAviFileStreamHeader info
        PVAviFileStreamHeaderStruct GetStreamHeaderStruct()
        {
            return iStreamHdr;
        }

        OSCL_HeapString<OsclMemAllocator> GetStreamMimeType();

        bool PalletChangeAvailable()
        {
            return iStreamHdr.iIsVidPalChangeAvailable;
        }

        bool ISDisabledByDefault()
        {
            return iStreamHdr.iAVISF_Disabled;
        }

        bool GetHandlerType(uint8* aHdlr, uint32& aSize);

        uint16 GetPriority()
        {
            return iStreamHdr.iPriority;
        }

        uint16 GetLanguage()
        {
            return iStreamHdr.iLanguage;
        }

        uint32 GetInitalFrames()
        {
            return iStreamHdr.iInitFrames;
        }

        uint32 GetScale()
        {
            return iStreamHdr.iScale;
        }

        uint32 GetRate()
        {
            return iStreamHdr.iRate;
        }

        OsclFloat GetSamplingRate()
        {
            return iStreamHdr.iSamplingRate;
        }

        uint32 GetStartTime()
        {
            return iStreamHdr.iStart;
        }

        uint32 GetStreamDuration()
        {
            return iStreamHdr.iLength;
        }

        uint32 GetStreamSuggestedBufferSize()
        {
            return iStreamHdr.iSugBufSize;
        }

        int32 GetQuality()
        {
            return iStreamHdr.iQuality;
        }

        uint32 GetBitsPerSample();

        uint32 GetSampleSize()
        {
            return iStreamHdr.iSampleSize;
        }

        rcFrameType GetRCFrame()
        {
            return iStreamHdr.ircFrame;
        }

        //methods to get PVAviFileStreamformat info
        uint32 GetStreamType()
        {
            return iStreamFmt.iType;
        }

        uint32 GetAudioFormat();

        uint32 GetNumAudioChannels();

        uint32 GetVideoWidth();

        uint32 GetVideoHeight(bool& rBottomUp);

        bool GetFormatSpecificInfo(uint8*& aBuff, uint32& aSize);

        bool GetCodecSpecificData(uint8*& aBuff, uint32& aSize);

    private:

        PV_AVI_FILE_PARSER_ERROR_TYPE   ParseStreamHeader(PVFile *aFp, uint32 aHdrSize);
        PV_AVI_FILE_PARSER_ERROR_TYPE   ParseStreamFormat(PVFile *aFp, uint32 aHdrSize);

        uint32                          iStreamListSize;
        PVAviFileStreamHeaderStruct     iStreamHdr;
        PVAviFileStreamFormatStruct     iStreamFmt;
        uint8*                          ipCodecSpecificHdrData;    //strd chunk
        uint32                          iCodecSpecificHdrDataSize;
        char                            iStreamName[MAX_STRN_SZ];  //strn chunk
};


#endif //#ifndef    PV_AVIFILE_STREAMLIST_H_INCLUDED

