//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSObject<OS_dispatch_source>, NSOperationQueue, NSString;

@interface ANSTimer : NSObject
{
    NSString *_timerIdentifier;
    CDUnknownBlockType _timerBlock;
    NSOperationQueue *_queue;
    NSObject<OS_dispatch_source> *_timerSource;
    double _timeInterval;
}

@property(retain, nonatomic) NSObject<OS_dispatch_source> *timerSource; // @synthesize timerSource=_timerSource;
@property(readonly, nonatomic) NSOperationQueue *queue; // @synthesize queue=_queue;
@property(copy, nonatomic) CDUnknownBlockType timerBlock; // @synthesize timerBlock=_timerBlock;
@property(nonatomic) double timeInterval; // @synthesize timeInterval=_timeInterval;
@property(readonly, nonatomic) NSString *timerIdentifier; // @synthesize timerIdentifier=_timerIdentifier;
- (void).cxx_destruct;
- (void)scheduleDispatchTimer;
- (void)executeBlock;
@property(readonly, nonatomic) double tolerance;
- (void)scheduleTimer;
- (void)dealloc;
- (id)initWithTimeInterval:(double)arg1 onQueue:(id)arg2 timerIdentifier:(id)arg3 block:(CDUnknownBlockType)arg4;

@end

