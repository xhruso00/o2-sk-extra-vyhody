//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDate, NSObject<OS_dispatch_queue>, NSObject<OS_dispatch_source>, NSString;

@interface APMAlarm : NSObject
{
    NSObject<OS_dispatch_queue> *_queue;
    NSObject<OS_dispatch_source> *_timer;
    NSString *_name;
    NSDate *_scheduledTimestamp;
}

@property(readonly, nonatomic) NSDate *scheduledTimestamp; // @synthesize scheduledTimestamp=_scheduledTimestamp;
- (void).cxx_destruct;
- (void)dealloc;
- (BOOL)hasActiveTimer;
- (void)cancel;
- (void)runAfterDelay:(double)arg1 withBlock:(CDUnknownBlockType)arg2;
- (id)initWithDispatchQueue:(id)arg1 name:(id)arg2;

@end
