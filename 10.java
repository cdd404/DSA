package jo;

import java.util.Scanner;
import mypack.Circle;
import mypack.Rectangle;
import mypack.Square;

public class Eg {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter radius of circle: ");
        double r = sc.nextDouble();
        Circle c = new Circle(r);
        c.area();

        System.out.print("Enter length and breadth of rectangle: ");
        double l = sc.nextDouble();
        double b = sc.nextDouble();
        Rectangle rect = new Rectangle(l, b);
        rect.area();

        System.out.print("Enter side of square: ");
        double s = sc.nextDouble();
        Square sq = new Square(s);
        sq.area();

        sc.close();
    }
}
