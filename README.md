# Lab 4: PThread Programming 
### 50 Points

**Objective:** Begin learning how to Use PThreads 

PThreads are one of the core methods that operating systems use to create and manage threads. They are used in all Unix based systems and also Linux as well. Microsoft uses their own systems. It's also worth noting that Linux uses a modified version of what Unix & macOS use. This is a "getting started" lab. You can use the provided pthread as a basis to help you. 

Here are the things you need to do in this lab:
+ Create more than three threads that loop for a long time (not forever, just a few thousand loops)
+ using `pthread_join` make it so that the main thread (*i.e.*, `main.c`) will not quit until all three threads are done.
+ Create a global variable that is read by all three threads
+ Create a variable that is read by all three threads that *IS NOT* global. 
+ Protect the reads of these shared variable via two seperate mutexes. 
+ Make it so that the three threads all modify the shared variables. Protect these writes by the mutexes.
+ Make it so that the three threads all modify the shared variables, by different values/methods. (For example one might add 2 another might multiply by 5). Protect these by the mutexes. 
+ **Hopefully this will work on GitHub Side, let's find out** Create a new branch of your code called `deadlock`. Modify your code above so that it will deadlock. Recall, this *IS NOT* just getting rid of the ups but rather it is a circular set of dependencies. 


