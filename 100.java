package mypack;

public class Rectangle {
    double l, b;

    public Rectangle(double l, double b) {
        this.l = l;
        this.b = b;
    }

    public void area() {
        System.out.println("Area of the Rectangle = " + (l * b));
    }
}
