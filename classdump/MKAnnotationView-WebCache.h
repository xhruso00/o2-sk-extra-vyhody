//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MKAnnotationView.h"

@interface MKAnnotationView (WebCache)
- (void)sd_cancelCurrentImageLoad;
- (void)sd_setImageWithURL:(id)arg1 placeholderImage:(id)arg2 options:(unsigned int)arg3 completed:(CDUnknownBlockType)arg4;
- (void)sd_setImageWithURL:(id)arg1 placeholderImage:(id)arg2 completed:(CDUnknownBlockType)arg3;
- (void)sd_setImageWithURL:(id)arg1 completed:(CDUnknownBlockType)arg2;
- (void)sd_setImageWithURL:(id)arg1 placeholderImage:(id)arg2 options:(unsigned int)arg3;
- (void)sd_setImageWithURL:(id)arg1 placeholderImage:(id)arg2;
- (void)sd_setImageWithURL:(id)arg1;
- (id)sd_imageURL;
@end
