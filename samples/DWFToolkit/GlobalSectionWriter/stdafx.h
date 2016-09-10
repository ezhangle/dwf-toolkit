//
//  Copyright (c) 2006 by Autodesk, Inc.
//
//  By using this code, you are agreeing to the terms and conditions of
//  the License Agreement included in the documentation for this code.
//
//  AUTODESK MAKES NO WARRANTIES, EXPRESS OR IMPLIED,
//  AS TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE
//  WORKS WHICH INCORPORATE IT.
//
//  AUTODESK PROVIDES THE CODE ON AN "AS-IS" BASIS
//  AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING
//  CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
//  OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//  Use, duplication, or disclosure by the U.S. Government is subject to
//  restrictions set forth in FAR 52.227-19 (Commercial Computer Software
//  Restricted Rights) and DFAR 252.227-7013(c)(1)(ii) (Rights in Technical
//  Data and Computer Software), as applicable.
//

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#include <iostream>


#include "dwfcore/File.h"
#include "dwfcore/MIME.h"
#include "dwfcore/String.h"
#include "dwfcore/StreamFileDescriptor.h"
#include "dwfcore/FileInputStream.h"

#include "dwf/Version.h"
#include "dwf/package/Constants.h"
#include "dwf/package/DefinedObject.h"
#include "dwf/package/EPlotSection.h"
#include "dwf/package/GlobalSection.h"
#include "dwf/package/CustomSection.h"
#include "dwf/package/writer/DWF6PackageWriter.h"

