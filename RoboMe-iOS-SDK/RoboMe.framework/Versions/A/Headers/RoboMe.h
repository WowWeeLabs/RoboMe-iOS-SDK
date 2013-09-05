//
//  RoboMe.h
//  RoboMe
//
//  Copyright (c) 2013 WowWee Group Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoboMeCommands.h"
#import "RoboMeCommandHelper.h"
#import "CommandPlayer.h"

@protocol RoboMeDelegate;

/** The RoboMe class provides a way to send and receive commands to WowWee's RoboMe Robot. */
@interface RoboMe : NSObject 

/** RoboMeDelegate to be called when commands are received from the robot. */
@property (nonatomic, strong) id<RoboMeDelegate> delegate;

/** Initialize RoboMe object with RoboMeDelegate delegate.
 
 @param delegate RoboMeDelegate to be called when commands are received from the robot.
 */
- (id)initWithDelegate: (id)delegate;

/** Start listening to events from RoboMe. */
-(void)startListening;

/** Stop listening to events from RoboMe. */
-(void)stopListening;

/** Is currently listening on the headphone jack.
 
 @return Is currently listening.
 */
-(BOOL)isListening;

/** Adds command to the queue to send to the Robot.
 
 @param robotCommand RobotCommand to send to the robot (see RoboMeCommands for a full list of commands).
 */
- (void)sendCommand: (RobotCommand)robotCommand;

/** Adds command to the queue to repeat a given number of times.
 
 @param robotCommand RobotCommand to send to the robot (see RoboMeCommands for a full list of commands).
 
 @param numberTimes Number of times to repeat. If set to -1, command repeats until stopPlaying is called.
 */
- (void)sendCommand: (RobotCommand)robotCommand repeat: (int)numberTimes;

/** Stops sending and clears command queue. */
- (void)stopSending;

/** Is currently sending a command.
 
 @return Is currently sending.
 */
- (BOOL)isSendingCommand;

/** Initializes the audio session.
 
    Note generally doesn't need to be called as it is run automatically
    the first time startListening method is called. */
- (void)initAudioSession;

/** Returns device volume.
 
 @return Volume is between 0.0-1.0 (1.0 max. volume).
 */
-(float)getVolume;

/** Returns RoboMe library version.
 
 @return RoboMe library version.
 */
-(NSString *)getLibVersion;

/** Returns whether or not RoboMe is connected.
 
 @return RoboMe is currently connection.
 */
- (BOOL)isRoboMeConnected;

/** Returns whether or not a headset is plugged in.
 
 @return Headset is plugged in
 */
- (BOOL)isHeadsetPluggedIn;

/** Returns whether or not audio route is to wired headset;
 
 @return Route is to headset
 */
- (BOOL)isRouteToWiredHeadset;

/** Returns whether or not audio route is to an Airplay device;
 
 @return Route is to Airplay
 */
- (BOOL)isOutputRouteToAirplay;

/** Returns whether or not audio route is to HDMI;
 
 @return Route is to HDMI
 */
- (BOOL)isOutputRouteToHDMI;

/** Returns whether or not audio route is to USB Audio Device;
 
 @return Route is to USB Audio Device
 */
- (BOOL)isRouteToUSBAudioDevice;

/** Returns whether or not audio route is to Bluetooth Device;
 
 @return Route is to Bluetooth Device
 */
- (BOOL)isRouteToBluetoothDevice;

/** Returns CommandPlayer object used to send commands.

 Note use RoboMe's sendCommand methods to send commands because it will make sure the sample rate is correctly set.
 The only reason you may need this method is to edit the sound queue dynamically.
 
 @return commandPlayer CommandPlayer object used to send commands.
 */
- (CommandPlayer *)commandPlayer;

/** if debug mode is enabled it will print debugging statements and
    play commands sounds out the phone speaker even if the headset isn't plugged in.

 @param enabled Enable/disable debug mode 
 */
-(void)setDebugEnabled: (BOOL)enabled;

@end

/** The RoboMeDelegate protocal allows you to receive commands from RoboMe and get information about the headset connection.  */
@protocol RoboMeDelegate <NSObject>

/** Called when a command received from RoboMe.
 
 @param command IncomingRobotCommand received from the robot (see RoboMeCommands for full list of incoming commands). */
- (void)commandReceived:(IncomingRobotCommand)command;

@optional
/** Called when RoboMe is connected */
- (void)roboMeConnected;

/** Called when RoboMe is disconnected
 
    Note if RoboMe is turned off while still connected this method is not called.
 */
- (void)roboMeDisconnected;

/** Called when headset is plugged in */
- (void)headsetPluggedIn;

/** Called when headset is unplugged */
- (void)headsetUnplugged;

/** Called when volume changes.
 
    Note this is useful for prompting the user to set the correct volume level for sending commands.
 
    @param volume Value is between 0.0-1.0 (1.0 max. volume). */
- (void)volumeChanged: (float)volume;

@end