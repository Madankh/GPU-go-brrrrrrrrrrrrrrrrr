using System;

public class Program
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Cylinder Volume Calculator");

        while (true) // Infinite loop until a valid choice is made
        {
            Console.WriteLine("Choose how you want to provide the dimensions of the cylinder:");
            Console.WriteLine("1. Radius");
            Console.WriteLine("2. Diameter");
            Console.WriteLine("3. Circumference");

            Console.Write("Enter your choice (1, 2, or 3): ");
            int choice;
            if (!int.TryParse(Console.ReadLine(), out choice) || choice < 1 || choice > 3)
            {
                Console.WriteLine("Invalid choice. Please enter 1, 2, or 3.");
                continue; // Ask for input again
            }

            double radius = 0;
            switch (choice)
            {
                case 1:
                    Console.Write("Enter the radius of the cylinder: ");
                    radius = double.Parse(Console.ReadLine());
                    break;
                case 2:
                    Console.Write("Enter the diameter of the cylinder: ");
                    double diameter = double.Parse(Console.ReadLine());
                    radius = CalculateRadiusFromDiameter(diameter);
                    break;
                case 3:
                    Console.Write("Enter the circumference of the cylinder: ");
                    double circumference = double.Parse(Console.ReadLine());
                    radius = CalculateRadiusFromCircumference(circumference);
                    break;
            }

            Console.Write("Enter the height of the cylinder: ");
            double height = double.Parse(Console.ReadLine());

            double volume = CalculateCylinderVolume(height, radius);
            Console.WriteLine($"The volume of the cylinder is: {volume:F2} cm^3");

            break; // Exit the loop after successful calculation
        }
    }

    public static double CalculateCylinderVolume(double height, double radius)
    {
        const double pi = Math.PI;
        double baseArea = pi * radius * radius;
        double volume = baseArea * height;
        return volume;
    }

    public static double CalculateRadiusFromDiameter(double diameter)
    {
        return diameter / 2;
    }

    public static double CalculateRadiusFromCircumference(double circumference)
    {
        return circumference / (2 * Math.PI);
    }
}
