#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct node{
    int product_id;
    string product_name;
    int quantity;
    struct node *next;
} ;

struct node * head = NULL; 


struct node *create_node(int product_id , string product_name , int quantity ){

    struct node *newnode = new node() ;
    newnode->product_id = product_id ;
    newnode->product_name = product_name ;
    newnode->quantity = quantity ;
    newnode->next = head ;
    head = newnode ;

    return newnode;

}


void write_data(){

    std::ofstream excelFile("InventoryManagementSystem/inventory.csv");

    if(excelFile.is_open()){
        excelFile<<"product_id,product_name,quantity\n";
        struct node *temp = head ;
        while( temp != NULL ){
            excelFile<<temp->product_id<<","<<temp->product_name<<","<<temp->quantity<<"\n";
            temp = temp->next;
        }
        excelFile.close();
        cout<<endl<<" Changes saved successfully"<<endl;
        return ;
    }
    cout<<endl<<" Error in opening the file to store the changes. Please don't exit the program without saving the changes."<<endl;

}

void load_data(){

    std::ifstream excelFile("InventoryManagementSystem/inventory.csv");

    if(excelFile.is_open()){

        string line ;

        if(!getline(excelFile,line)){  // Empty File and also avoids header ;
            excelFile.close();
            return ;
        }

        while(getline(excelFile,line)){
            if(line.empty()) continue;

            stringstream ss(line);
            string id , product_name , Quantity ;
            if(getline( ss , id , ',') && getline( ss , product_name , ',') && getline( ss , Quantity , ',')){
                int product_id = stoi(id);
                int quantity = stoi(Quantity);
                create_node( product_id , product_name , quantity );
                
            }
        }
        return ;
    }

    cout<<endl<<" Couldn't load your data"<< endl << " Starting trial Inventory System, no changes would save" ;
    return ;

}


struct node *search_product_name( string product_name ){

    struct node *temp = head;

    while( temp != NULL){
        if( product_name == temp->product_name ){
            return temp;
        }
        temp = temp->next ;
    }

    return NULL;
}


struct node *search_product_id(int product_id){
    struct node *temp = head;

    while( temp != NULL){
        if( product_id == temp->product_id ){
            return temp;
        }
        temp = temp->next ;
    }

    return NULL;

}


void add_new_product_to_inventory(){
    int product_id;
    string product_name;
    int quantity;
    cout<<endl<<"\t\t---------- STOCK NEW PRODUCT TO THE INVENTORY ----------\t\t"<<endl;
    cout<<" Enter the product name ";
    cin.ignore() ;
    getline( cin , product_name ) ;

    if(search_product_name( product_name ) != NULL ){
        cout<<endl<<" The product is already in the inventory";
        return;
    }

    cout<<endl<<" Enter the product id :- ";
    cin>>product_id;

    if(search_product_id(product_id) != NULL){
        cout<<endl<<" The product id is registered with other product";
        return;
    }

    cout<<endl<<" Enter the non zero quantity :-  ";
    cin>>quantity;
    
    if( quantity < 0 ){
        cout<<endl<<" Quantity can't be negative ";
        return;
    }

    struct node *newnode;
    newnode = create_node(product_id , product_name , quantity);

    cout<<endl<<" The product "<< newnode->product_name<<" is added in the inventory. "<<" Quantity : "<<newnode->quantity<<". ";

}

void sell_product(){

    string product_name = "None" ;
    int quantity = 0 ;

    cout<<endl<<endl<<"\t\t---------- STOCK OUT PRODUCT ----------\t\t"<<endl;

    cout<<endl<<" Enter the product name to sell :- ";
    cin.ignore();
    getline( cin , product_name ) ;
    struct node *temp = search_product_name( product_name );

    if(temp != NULL){

        cout<<" Enter quantity to sell :- ";
        cin>> quantity ;

        if( quantity <= 0 ){
            cout<<endl<<" Quantity can't be negative or zero"<<endl;
            return ;
        }

        if( quantity > temp->quantity){
            cout<<endl<<" The product "<<product_name<<" has only "<< temp->quantity <<" units.\n Purchase the stock\n" ;
            return ;
        }

        temp->quantity = temp->quantity - quantity ;
        cout<<endl<<" The product "<< product_name <<" "<< quantity <<" is sold."<<endl;
        cout<<" Remaining quantity "<< temp->quantity<<endl<<" Thankyou \n" ;

        return ;
    }

    cout<<endl<<" Product not found\n";
    return ;
}

void restock_product(){
    string product_name = "None" ;
    int quantity = 0 ;

    cout<<endl<<endl<<"\t\t---------- RESTOCK PRODUCT (IN) ----------\t\t"<<endl;

    cout<<endl<<" Enter the product name to restock :- ";
    cin.ignore() ;
    getline( cin , product_name ) ;
 
    struct node *temp = search_product_name( product_name );

    if(temp){

        cout<<" Enter quantity to sell :- ";
        cin>> quantity ;

        if( quantity <= 0 ){
            cout<<endl<<" Quantity can't be negative or zero"<<endl;
            return;
        }

        temp->quantity = temp->quantity + quantity ;
        
        cout<<endl<<" "<< quantity <<" units of " << product_name << " is restocked\n";
        cout<<" Current Quantity : " << temp->quantity <<endl;

        return ;
    }

    cout << endl << " Product not found ";
    return ;
}

void view_inventory(){

    struct node *temp = head ;

    if( head ){

        cout<<endl<<"\t\t--------- INVENTORY ----------" << endl ;
        cout <<endl << " Product ID \t\t\t Product \t Quantity \t\n";

        while( temp != NULL ){
            cout << " " << temp->product_id << " \t " << temp->product_name <<" \t " << temp->quantity <<endl ;
            temp = temp->next ;
        }

        cout<<" Thankyou" <<endl;
        return ;

    }

    cout<<endl<<" No products in the inventory " <<endl ;
    return ;

}



 int main(){

    load_data();

    int choice = -1 ;
    while(true){
        cout <<endl<<endl<< "\t\t---------- MENU ----------\t\t"<<endl;
        cout << endl << "\t\t\t 1. VIEW INVENTORY \t\t\t" <<endl;
        cout << endl << "\t\t\t 2. ADD NEW PRODUCT TO INVENTORY \t\t\t" <<endl;
        cout << endl << "\t\t\t 3. SELL PRODUCT \t\t\t" <<endl;
        cout << endl << "\t\t\t 4. RESTOCK PRODUCT \t\t\t" <<endl;
        cout << endl << "\t\t\t 5. SAVE CHANGES \t\t\t" <<endl ;
        cout << endl << "\t\t\t 6. EXIT \t\t\t" <<endl;

        cout << endl << " Enter command (1/2/3/4/5) :- ";
        cin >> choice ; 

        switch (choice) {
            case 1 : view_inventory();
                break ;

            case 2 : add_new_product_to_inventory();
                break ;
            case 3 : sell_product() ;
                break ;

            case 4 : restock_product();
                break ;

            case 5 : write_data();
                break ; 

            case 6 :
                write_data();
                cout << endl << " Exiting the program ";
                cout << endl ;
                exit(0);
                break ;
        }
    }
 }