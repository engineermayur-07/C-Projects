#include <iostream>
#include <string>
using namespace std;

struct node{
    int product_id;
    char product_name[20];
    int quantity;
    struct node *next;
    struct node *prev;
} ;

struct node * head = NULL; 


struct node *create_node(int product_id , char product_name[] , int quantity ){

    struct node *newnode = malloc(sizeof(struct node));
    newnode->product_id = product_id ;
    newnode->product_name = product_name ;
    newnode->quantity = quantity ;

    newnode->next = head ;
    head = newnode ;

    return newnode;

}


int search_product_name( char product_name ){

    struct node *temp = head;

    while( temp != NULL){
        if( product_name == temp->product_name ){
            return 1;
        }
    }

    return 0;
}


int search_product_id(int product_id){
    struct node *temp = head;

    while( temp != NULL){
        if( product_id == temp->product_id ){
            return 1;
        }
    }

    return 0;

}


void add_new_product_to_inventory(){
    int product_id;
    char product_name[20];
    int quantity;
    cout<<"\t\t---------- ADDING TO THE INVENTORY ----------\t\t"<<endl;
    cout<<" Enter the product name ";
    cin>>product_name;

    if(search_product_name( product_name )){
        cout<<endl<<" The product is already in the inventory";
        return;
    }

    cout<<endl<<" Enter the product id :- ";
    cin>>product_id;

    if(search_product_id(product_id)){
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

    cout<<endl<<" The product "<< newnode->product<<" is added in the inventory. "<<" Quantity : "<<newnode->quantity<<". ";
 
}