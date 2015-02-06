
#ifndef PVMP4FFCN_TUNABLES_H_INCLUDED
#define PVMP4FFCN_TUNABLES_H_INCLUDED

//Default NODE COMMAND vector reserve size
#define PVMF_MP4FFCN_COMMAND_VECTOR_RESERVE 10

//Starting value for command IDs
#define PVMF_MP4FFCN_COMMAND_ID_START 20000

// Default port vector reserve size
#define PVMF_MP4FFCN_PORT_VECTOR_RESERVE 1

#define PVMF_MP4FFCN_MAX_INPUT_PORT 3
#define PVMF_MP4FFCN_MAX_OUTPUT_PORT 0

// Port message queue settings
#define PVMF_MP4FFCN_PORT_CAPACITY 50
#define PVMF_MP4FFCN_PORT_RESERVE 50
#define PVMF_MP4FFCN_PORT_THRESHOLD 50

// Default video track config parameters
#define PVMF_MP4FFCN_VIDEO_BITRATE 52000
#define PVMF_MP4FFCN_VIDEO_FRAME_WIDTH 176
#define PVMF_MP4FFCN_VIDEO_FRAME_HEIGHT 144
#define PVMF_MP4FFCN_VIDEO_TIMESCALE 1000
#define PVMF_MP4FFCN_VIDEO_FRAME_RATE 15
#define PVMF_MP4FFCN_VIDEO_IFRAME_INTERVAL 10
#define PVMF_MP4FFCN_VIDEO_H263_PROFILE 0
#define PVMF_MP4FFCN_VIDEO_H263_LEVEL 40

// Default audio track config parameters
#define PVMF_MP4FFCN_AUDIO_BITRATE 12200
#define PVMF_MP4FFCN_AUDIO_TIMESCALE 8000
#define PVMF_MP4FFCN_AUDIO_NUM_CHANNELS 2
#define PVMF_MP4FFCN_AUDIO_SAMPLING_RATE 8000
#define PVMF_MP4FFCN_AUDIO_BITS_PER_SAMPLE 16

// Default text track config parameters
#define PVMF_MP4FFCN_TEXT_BITRATE 0
#define PVMF_MP4FFCN_TEXT_FRAME_WIDTH 176
#define PVMF_MP4FFCN_TEXT_FRAME_HEIGHT 177
#define PVMF_MP4FFCN_TEXT_TIMESCALE 90000

#endif /*PVMP4FFCN_TUNABLES_H_INCLUDED*/