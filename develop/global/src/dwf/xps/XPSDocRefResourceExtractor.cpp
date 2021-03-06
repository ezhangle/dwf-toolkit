//
//  Copyright (c) 2006 by Autodesk, Inc.
//
//  By using this code, you are agreeing to the terms and conditions of
//  the License Agreement included in the documentation for this code.
//
//  AUTODESK MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
//  OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT. AUTODESK
//  PROVIDES THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
//  LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
//  OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//  Use, duplication, or disclosure by the U.S. Government is subject to
//  restrictions set forth in FAR 52.227-19 (Commercial Computer Software
//  Restricted Rights) and DFAR 252.227-7013(c)(1)(ii) (Rights in Technical
//  Data and Computer Software), as applicable.
//
//
#include "dwfcore/XMLParser.h"
#include "dwfcore/BufferOutputStream.h"
using namespace DWFCore;

#include "dwf/xps/XPSDocRefResourceExtractor.h"
#include "dwf/xps/Constants.h"
#include "dwf/dwfx/Constants.h"
#include "dwf/opc/ZipFileReader.h"
using namespace DWFToolkit;

_DWFTK_API
XPSDocRefResourceExtractor::XPSDocRefResourceExtractor( DWFInputStream* pInputStream,
                                                                bool bOwnStream )
throw( DWFException )
                       : _pFixedPagePartStream( pInputStream )
                       , _bOwnStream( bOwnStream )
{
    _pParser = DWFCORE_ALLOC_OBJECT( DWFXMLParser( this ) );
    if (_pParser == NULL)
    {
        _DWFCORE_THROW( DWFMemoryException, /*NOXLATE*/L"Unable to allocate parser" );
    }
}

_DWFTK_API
XPSDocRefResourceExtractor::~XPSDocRefResourceExtractor()
throw()
{
    DWFCORE_FREE_OBJECT( _pParser );

    if (_bOwnStream)
    {
        DWFCORE_FREE_OBJECT( _pFixedPagePartStream );
    }
}

_DWFTK_API
void
XPSDocRefResourceExtractor::parse()
throw()
{
    _pParser->parseDocument( *_pFixedPagePartStream );
}

_DWFTK_API
void
XPSDocRefResourceExtractor::notifyStartElement( const char* zName,
                                                    const char** ppAttributeList )
throw()
{	
    //
    // if this is the start of a Canvas element increment the depth
    //
    if (DWFCORE_COMPARE_ASCII_STRINGS( zName, XPSXML::kzElement_DocumentReference ) == 0)
    {
        //_nCanvasElementDepth++;
	    size_t iAttrib = 0;
        const char* pAttributeName = NULL;
        const char* pAttributeValue = NULL;

        //
        // loop through the attributes looking for the name attribute
        //
        for(; ppAttributeList[iAttrib]; iAttrib += 2)
        {
            pAttributeName = ppAttributeList[iAttrib];
            pAttributeValue = ppAttributeList[iAttrib + 1];
			if(DWFCORE_COMPARE_ASCII_STRINGS(pAttributeName, XPSXML::kzAttribute_Source) == 0)
			{
				DWFString value(pAttributeValue);
				_oDocumentURIs.push_back(value);				
			}
		}
    }
}

_DWFTK_API
void
XPSDocRefResourceExtractor::notifyEndElement( const char* /*zName*/ )
throw()
{
}

_DWFTK_API
void
XPSDocRefResourceExtractor::notifyStartNamespace( const char* /*zPrefix*/,
                                                      const char* /*zURI*/ )
throw()
{
    ;
}

_DWFTK_API
void
XPSDocRefResourceExtractor::notifyEndNamespace( const char* /*zPrefix*/ )
throw()
{
    ;
}

_DWFTK_API
void
XPSDocRefResourceExtractor::notifyCharacterData( const char* /*zCData*/, 
                                                     int         /*nLength*/ ) 
throw()
{
    ;
}

_DWFTK_API
DWFInputStream*
XPSDocRefResourceExtractor::getResourceStream( const DWFString& /*zLocator*/ )
throw( DWFException )
{
	return NULL;
}
