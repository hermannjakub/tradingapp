#include "httplib.h"
#include <iostream>

int main() {
    httplib::Server svr;

    // Defining, what happens if Python asks about "/api/price"
    svr.Get("/api/price", [](const httplib::Request&, httplib::Response& res) {
        
        // For now the price is set as constant.
        std::string json_data = "{\"symbol\": \"BTC\", \"price\": 45000.50}";
        
        // Returning the data to python
        res.set_content(json_data, "application/json");
    });

    std::cout << "Serwer C++ dziala na porcie 8080..." << std::endl;
    
    // Turning on the server (program works constantly, waiting for comms)
    svr.listen("localhost", 8080);
}