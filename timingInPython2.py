import threading, time
from twisted.internet import task

def set_interval(func, sec):
    def func_wrapper():
        set_interval(func, sec)
        func()
    t = threading.Timer(sec, func_wrapper)
    t.start()
    return t

def printmuk(inval, inval2):
	print ("%s %s") % (inval, inval2)
	outTime = time.time()
	print outTime

t = threading.Timer(0.000, printmuk, args=["Hello", "Mukund"])
print time.time()
t.start()
# =====================================================================
def pri():
	print "hello"


myNewTask = task.LoopingCall(pri)
print myNewTask.start
time.sleep(5)
myNewTask.start(1, now=True)

def stopTask():
	myNewTask.stop()

newt = threading.Timer(6, stopTask)
newt.start()