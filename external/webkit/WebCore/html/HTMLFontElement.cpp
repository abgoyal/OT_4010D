

#include "config.h"
#include "HTMLFontElement.h"

#include "CSSPropertyNames.h"
#include "CSSValueKeywords.h"
#include "HTMLNames.h"
#include "MappedAttribute.h"

using namespace WTF;

namespace WebCore {

using namespace HTMLNames;

HTMLFontElement::HTMLFontElement(const QualifiedName& tagName, Document* document)
    : HTMLElement(tagName, document)
{
    ASSERT(hasTagName(fontTag));
}

// Allows leading spaces.
// Allows trailing nonnumeric characters.
// Returns 10 for any size greater than 9.
static bool parseFontSizeNumber(const String& s, int& size)
{
    unsigned pos = 0;
    
    // Skip leading spaces.
    while (isSpaceOrNewline(s[pos]))
        ++pos;
    
    // Skip a plus or minus.
    bool sawPlus = false;
    bool sawMinus = false;
    if (s[pos] == '+') {
        ++pos;
        sawPlus = true;
    } else if (s[pos] == '-') {
        ++pos;
        sawMinus = true;
    }
    
    // Parse a single digit.
    if (!isASCIIDigit(s[pos]))
        return false;
    int num = s[pos++] - '0';
    
    // Check for an additional digit.
    if (isASCIIDigit(s[pos]))
        num = 10;
    
    if (sawPlus) {
        size = num + 3;
        return true;
    }
    
    // Don't return 0 (which means 3) or a negative number (which means the same as 1).
    if (sawMinus) {
        size = num == 1 ? 2 : 1;
        return true;
    }
    
    size = num;
    return true;
}

bool HTMLFontElement::mapToEntry(const QualifiedName& attrName, MappedAttributeEntry& result) const
{
    if (attrName == sizeAttr ||
        attrName == colorAttr ||
        attrName == faceAttr) {
        result = eUniversal;
        return false;
    }
    
    return HTMLElement::mapToEntry(attrName, result);
}

bool HTMLFontElement::cssValueFromFontSizeNumber(const String& s, int& size)
{
    int num;
    if (!parseFontSizeNumber(s, num))
        return false;
        
    switch (num) {
        case 2: 
            size = CSSValueSmall; 
            break;
        case 0: // treat 0 the same as 3, because people expect it to be between -1 and +1
        case 3: 
            size = CSSValueMedium; 
            break;
        case 4: 
            size = CSSValueLarge; 
            break;
        case 5: 
            size = CSSValueXLarge; 
            break;
        case 6: 
            size = CSSValueXxLarge; 
            break;
        default:
            if (num > 6)
                size = CSSValueWebkitXxxLarge;
            else
                size = CSSValueXSmall;
    }
    return true;
}

void HTMLFontElement::parseMappedAttribute(MappedAttribute *attr)
{
    if (attr->name() == sizeAttr) {
        int size;
        if (cssValueFromFontSizeNumber(attr->value(), size))
            addCSSProperty(attr, CSSPropertyFontSize, size);
    } else if (attr->name() == colorAttr) {
        addCSSColor(attr, CSSPropertyColor, attr->value());
    } else if (attr->name() == faceAttr) {
        addCSSProperty(attr, CSSPropertyFontFamily, attr->value());
    } else
        HTMLElement::parseMappedAttribute(attr);
}

String HTMLFontElement::color() const
{
    return getAttribute(colorAttr);
}

void HTMLFontElement::setColor(const String& value)
{
    setAttribute(colorAttr, value);
}

String HTMLFontElement::face() const
{
    return getAttribute(faceAttr);
}

void HTMLFontElement::setFace(const String& value)
{
    setAttribute(faceAttr, value);
}

String HTMLFontElement::size() const
{
    return getAttribute(sizeAttr);
}

void HTMLFontElement::setSize(const String& value)
{
    setAttribute(sizeAttr, value);
}

}
