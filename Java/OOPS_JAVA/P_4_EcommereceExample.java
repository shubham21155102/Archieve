package OOPS_JAVA;

import java.sql.Connection;
import java.util.HashMap;
import java.util.Map;

// class DatabaseConnection {
//     private static DatabaseConnection instance;
//     private Connection connection;

//     private DatabaseConnection() {
//         // Initialize connection
//         connection = // Create the connection
//     }

//     public static DatabaseConnection getInstance() {
//         if (instance == null) {
//             instance = new DatabaseConnection();
//         }
//         return instance;
//     }

//     public Connection getConnection() {
//         return connection;
//     }
// }
class Logger {
    private static Logger instance;

    private Logger() {
        // Setup logging configurations (file, database, etc.)
    }

    public static Logger getInstance() {
        if (instance == null) {
            instance = new Logger();
        }
        return instance;
    }

    public void log(String message) {
        System.out.println("Log entry: " + message);  // or write to file
    }
}
class Product {
    private String productId;
    private String name;
    private double price;

    public Product(String productId, String name, double price) {
        this.productId = productId;
        this.name = name;
        this.price = price;
    }

    public String getProductId() {
        return productId;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }
}
class CacheManager {
    private static CacheManager instance;
    private Map<String, Product> productCache;

    private CacheManager() {
        productCache = new HashMap<>();
    }

    public static CacheManager getInstance() {
        if (instance == null) {
            instance = new CacheManager();
        }
        return instance;
    }

    public Product getProductFromCache(String productId) {
        return productCache.get(productId);
    }

    public void addProductToCache(String productId, Product product) {
        productCache.put(productId, product);
    }
}
public class P_4_EcommereceExample {

}
