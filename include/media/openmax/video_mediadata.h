/*
 * Copyright (c) 2011 The Khronos Group Inc. 
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions: 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software. 
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
 *
 */

#ifndef __VIDEO_MEDIADATA_H__
#define __VIDEO_MEDIADATA_H__

#define kMetadataBufferTypeCameraSource_act 0x0//same as camerasource from android
#define kMetadataBufferTypeImageBackground_act 0x100

typedef struct vce_private{
	int noffset;
	int nfilledlen;
}vce_private;

typedef struct {
    int metadataBufferType;
    void* handle;
    int off_x;
    int off_y;
    int crop_w;
    int crop_h;
    int nAlpha;
	vce_private vce_attribute;
}video_metadata_t;


typedef struct{
	unsigned int nativehanle[3];
	int ion_share_fd;//ION share Fd for MMAP VirAddr
	/*
		ptrVir = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, ion_share_fd, 0);
	*/
	int     magic;
	int     flags;
	int     size;
	int     offset;

	unsigned int revoffset[7];
	int phys_addr;
	int ion_handle_t;//unuse here
}video_handle_t;
#endif

