//
//  ThreadSample.c
//  Threads
//
//  Created by Aaron David Block on 2/1/19.
//  Copyright © 2019 Austin College. All rights reserved.
//

#include "ThreadSample.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

// Pthread doc can be found here : https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/Multithreading/CreatingThreads/CreatingThreads.html
// Linux doc on pthread example https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html

struct thread_communication {
    pthread_mutex_t* mutext;
    int* sharedData;
    char* message;
};

void* PosixThreadMainRoutine(void* data)
{
    //With Mutex, there is not longer intermixing (Maybe a little at begingin because of slowness of prtinging)
    struct thread_communication* tc = (struct thread_communication*)data;
    
    
    char* message = tc->message;
    int* sharedData = tc->sharedData;
    pthread_mutex_lock(tc->mutext);
    
    for(int i = 0;i< 10000;i++){
        (*sharedData) += 5;
        printf("%s: %d\n",message, i);
    }
    pthread_mutex_unlock(tc->mutext);
    
    return NULL;
}


void LaunchThread()
{
    // Create the thread using POSIX routines.
    pthread_attr_t  attr,attr2;
    pthread_t       posixThreadID,posixThreadID2;
    int             returnVal, returnVal2;
    
    returnVal = pthread_attr_init(&attr);
    assert(!returnVal);
    returnVal2 = pthread_attr_init(&attr2);
    assert(!returnVal2);
    
    
    char* message1 = "I'm thread 1";
    char* message2 = "I'm thread 2";
    int* sharedData = (int*)malloc(sizeof(int));
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    
    struct thread_communication tc1;
    struct thread_communication tc2;
    tc1.message = message1;
    tc1.mutext = &mutex;
    tc1.sharedData = sharedData;
    
    tc2.message = message2;
    tc2.mutext = &mutex;
    tc2.sharedData = sharedData;
    
    int threadError = pthread_create(&posixThreadID, &attr, &PosixThreadMainRoutine, &tc1);
    int threadError2 = pthread_create(&posixThreadID2, &attr, &PosixThreadMainRoutine, &tc2);
    
    //Will Wait until thread is done before continuning to execute.
    
    pthread_join(posixThreadID, NULL);
    pthread_join(posixThreadID2, NULL);
    
    printf("I'm done!, the shared data value is %d\n", *sharedData);
    free(sharedData);
    
    //Kill that thread and get the error message
    returnVal = pthread_attr_destroy(&attr);
    returnVal2 = pthread_attr_destroy(&attr2);
    assert(!returnVal);
    if (threadError != 0)
    {
        // Report an error.
    }
    
    
    assert(!returnVal2);
    if (threadError2 != 0)
    {
        // Report an error.
    }
}
