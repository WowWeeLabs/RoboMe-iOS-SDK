//
//  CommandPlayer.h
//  HeadphoneConnectionLib
//
//  Created by Josh Savage on 27/5/13.
//  Copyright (c) 2013 WowWee Group Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface CommandPlayer : NSObject <AVAudioPlayerDelegate>

/** Plays command sound file.
    If another command is already playing it will play after it is finished. If you want to interrupt the current sound or clear the queue call stopPlaying.
 
 @param soundFile Command sound file to play
 */
-(void)playCommand: (NSString *)soundFile;

/** Plays commands repeating a specific number of times.

 @param soundFile Command sound file to play.
 @param numberTimes Number of times to play command.
 */
-(void)playCommand: (NSString *)soundFile repeat: (int)numberTimes;

/** Stops playing and clears queue. */
-(void)stopPlaying;

/** Returns if currently playing or there are still sounds in the queue */
- (BOOL)isPlaying;

/** Gap between commands in milliseconds (default 100ms) */
@property (nonatomic) int interval;

/** AVAudioPlayer used to play sounds. */
@property (nonatomic, retain, readonly) AVAudioPlayer *player;

/** Read only queue of command sound files to play. */
@property (nonatomic, retain, readonly) NSMutableArray *queue;

@end
