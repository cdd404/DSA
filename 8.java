package jo; 
class Outer{ 
 String so = "This is Outer Class"; 
void display() 
 { 
 System.out.println(so); 
 } 
void test(){ 
 Inner obj2 = new Inner(); 
obj2.display(); 
 } 
//this is an inner class
class Inner{ 
 String si ="This is inner Class"; 
void display(){ 
 System.out.println(si); 
 } 
 } 
 } 
class InnerClassDemo{ 
public static void main(String args[]){ 
 Outer obj1 = new Outer(); 
obj1.display(); 
obj1.test(); 
 } 
 }
