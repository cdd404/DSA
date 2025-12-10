class DivisionByZeroDemo { 
public static void main(String[] args) { 
int dividend = 10; 
int divisor = 0; 
try { 
if (divisor == 0) 
 { 
throw new ArithmeticException("Divide by zero error "); 
 } 
int result = dividend / divisor; 
 System.out.println("Result: " + result); 
 } 
catch (ArithmeticException e) 
 { 
 System.err.println("Caught an exception: " + e.getMessage()); 
 } 
finally
 { 
 System.out.println("End of Program !!"); 
 } 
 } 
 }
