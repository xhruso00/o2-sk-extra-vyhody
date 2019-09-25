//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSObject<OS_dispatch_queue>;

@interface APMScheduler : NSObject
{
    NSObject<OS_dispatch_queue> *_workerQueue;
}

+ (BOOL)checkOnBackgroundThreadWithMethodName:(id)arg1;
@property(readonly, nonatomic) NSObject<OS_dispatch_queue> *workerQueue; // @synthesize workerQueue=_workerQueue;
- (void).cxx_destruct;
- (void)dispatchSyncOnWorkerQueueBlockID:(id)arg1 block:(CDUnknownBlockType)arg2;
- (void)scheduleOnWorkerQueueBlockID:(id)arg1 block:(CDUnknownBlockType)arg2;
- (id)initWithWorkerQueueLabel:(id)arg1;

@end
