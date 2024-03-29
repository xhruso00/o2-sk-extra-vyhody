//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class UNMutableNotificationContent;

@interface FIRMessagingExtensionHelper : NSObject
{
    CDUnknownBlockType _contentHandler;
    UNMutableNotificationContent *_bestAttemptContent;
}

@property(retain, nonatomic) UNMutableNotificationContent *bestAttemptContent; // @synthesize bestAttemptContent=_bestAttemptContent;
@property(copy, nonatomic) CDUnknownBlockType contentHandler; // @synthesize contentHandler=_contentHandler;
- (void).cxx_destruct;
- (void)deliverNotification;
- (void)loadAttachmentForURL:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (void)populateNotificationContent:(id)arg1 withContentHandler:(CDUnknownBlockType)arg2;

@end

