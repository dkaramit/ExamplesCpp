import ctypes


loadedClass = ctypes.CDLL('./Example.so')#call the main.py in the same directory as Example.so

double=ctypes.c_double
void_p=ctypes.c_void_p



loadedClass.INIT.argtypes= double, double #argument  types
loadedClass.INIT.restype = void_p #return types


loadedClass.DEL.argtypes= void_p,
loadedClass.DEL.restype = None

loadedClass.SUM.argtypes= void_p,
loadedClass.SUM.restype = double

loadedClass.MUL.argtypes= void_p,
loadedClass.MUL.restype = double

loadedClass.SUMWITH.argtypes= void_p,double
loadedClass.SUMWITH.restype = double



class calcClass:
    def __init__(self, x, y):
        '''constructor'''
        self.voidP = void_p#you don't really need this, but it's good to remember what it is
        self.voidP=loadedClass.INIT(x,y)

    def sum(self):
        '''the sum method'''
        return loadedClass.SUM(self.voidP)

    def mul(self):
        '''the mul method'''
        return loadedClass.MUL(self.voidP)

    def sumWith(self,z):
        '''the sumWith method'''
        return loadedClass.SUMWITH(self.voidP,z)


    def __del__(self):
        '''Destructor for the class. Deallocates the pointer to the object created.'''
        loadedClass.DEL(self.voidP)
        del self.voidP
