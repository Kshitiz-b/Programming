abstract class Supermarket {

    abstract void stockAvailability();

    abstract void printSaleReport();
}

class Food_products extends Supermarket {
    int quantity;
    int vat;
    double price;
    int total_Sales;

    Food_products(int q, int v, double p, int s) {
        quantity = q;
        vat = v;
        price = p;
        total_Sales = s;
    }

    void stockAvailability() {
        if (quantity > total_Sales)
            System.out.println("The Stock is available: " + quantity);
        else
            System.out.println("The Stock is not available");
    }

    void printSaleReport() {
        if (quantity > total_Sales)
            System.out.println("The total Sale report is " + total_Sales);
    }
}

class electronic_accessories extends Supermarket {
    int quantity;
    int vat;
    double price;
    int total_Sales;

    electronic_accessories(int q, int v, double p, int s) {
        quantity = q;
        vat = v;
        price = p;
        total_Sales = s;
    }

    void stockAvailability() {
        if (quantity > total_Sales)
            System.out.println("The Stock is available: " + quantity);
        else
            System.out.println("The Stock is not available");
    }

    void printSaleReport() {
        if (quantity > total_Sales)
            System.out.println("The total Sale report is " + total_Sales);
    }
}

public class Main1 {
    public static void main(String[] args) {
        Food_products f1 = new Food_products(20, 5, 5000.00, 10);
        System.out.println("For Food Products");
        f1.stockAvailability();
        f1.printSaleReport();
        System.out.println();
        
        electronic_accessories e1 = new electronic_accessories(10, 12, 10000.00, 5);
        System.out.println("For Electronic Accessories");
        e1.stockAvailability();
        e1.printSaleReport();
    }
}