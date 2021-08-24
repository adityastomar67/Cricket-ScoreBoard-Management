class A  
{ 
   int z; 
public: 
    int x; 
 
}; 
  
class B : public A 
{ 
    // x is public 
    // y is protected 
    // z is not accessible from B 
}; 
  
class C : protected A 
{ 
    // x is protected 
    // y is protected 
    // z is not accessible from C 
}; 
  
class D : private A    // 'private' is default for classes 
{ 
    // x is private 
    // y is private 
    // z is not accessible from D 
};