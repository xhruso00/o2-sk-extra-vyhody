//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class APMDatabase;

@interface APMAudience : NSObject
{
    APMDatabase *_database;
}

+ (BOOL)isValidAudienceProto:(id)arg1 usedAudienceIDs:(id)arg2 error:(id *)arg3;
+ (id)updatedFilterResultWithFilterID:(int)arg1 audienceID:(int)arg2 currentFilterResult:(id)arg3 newEvaluationResult:(id)arg4 dynamicFilterTimestamps:(id)arg5 sequenceFilterTimestamps:(id)arg6;
+ (BOOL)isFilterResult:(id)arg1 trueForFilterID:(int)arg2;
- (void).cxx_destruct;
- (BOOL)resultsForBundling:(id *)arg1;
- (BOOL)maybeDeleteStaleFilterResults:(id)arg1;
- (BOOL)updateAudiences:(id)arg1;
- (BOOL)evaluateFiltersForNanoUserProperty:(id)arg1 cachedSequenceEvaluationTimestamps:(id)arg2;
- (BOOL)evaluateFiltersForUserProperty:(id)arg1;
- (BOOL)evaluateFiltersForUserProperty:(id)arg1 cachedSequenceEvaluationTimestamps:(id)arg2;
- (BOOL)evaluateFiltersForEventName:(id)arg1 eventParameters:(id)arg2 eventAggregates:(id)arg3 eventTimestamp:(double)arg4 cachedSequenceEvaluationTimestamps:(id)arg5;
- (BOOL)evaluateFiltersForEvent:(id)arg1 eventAggregates:(id)arg2 cachedSequenceEvaluationTimestamps:(id)arg3;
- (id)initWithDatabase:(id)arg1;

@end

