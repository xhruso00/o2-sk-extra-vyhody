//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CLSURLSessionDataDelegate.h"

@class CLSURLSessionDownloadTask, NSURL;

@protocol CLSURLSessionDownloadDelegate <CLSURLSessionDataDelegate>
- (void)downloadTask:(CLSURLSessionDownloadTask *)arg1 didFinishDownloadingToURL:(NSURL *)arg2;
@end

