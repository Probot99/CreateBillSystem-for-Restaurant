#include<stdio.h>
#include<string.h>
struct items{
char item[50];
float price;
int qty;
};
struct orders{
    char customer[50];
    char date[30];
    int numofitem ;
     struct items itm[50];
};
void generatebillheader(char name[50],char date[50]){
    printf("\n\n");
    // printf("\n\n\n\t\t\t\t\t%s",name);
    printf("\t    ADV.  Resttaurant");
    printf("\n\t  ----------------------   ");
    printf("\n Date :%s",date);
    printf("\nInvoice To:%s",name);
    printf("\n");
    printf("---------------------------------------------------\n");
    printf("Item \t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n-------------------------------------------------\n");
    printf("\n\n");


}
void generaterbilllbody(char item[30],int qty,float price){
    printf("%s\t\t",item);
    printf("%d\t\t",qty);
    printf("%.2f\t\t",qty*price);
    printf("\n");
}
void generatebillfoter(float total){
    printf("\n");
    float dis=0.1*total;
    float netTotal=total-dis;
    float cgst =0.09*netTotal,grandtotal=netTotal+2*cgst;
    printf("---------------------------------------\n");
    printf("Sub Total \t\t\t%.2f",total);
    printf("\n Discount @10%s\t\t\t%0.2f","%",dis);

    printf("\n\t\t\t\t---------");
    printf("\nNet Total \t\t\t%0.2f",netTotal);
    printf("\nCGST @9 %s \t\t\t %.2f ","%",cgst);
    printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n---------------------------------------------------");
    printf("\n Grand Total \t\t\t%.2f",grandtotal);
    printf("\n----------------------------------------------------\n");


}
int main(){
    int opt,n ,invoce=0;
    float total;
    struct orders ord;
    struct orders order;
    char savebill='y', con='y';
    char name [50];
    FILE *fp;
int k=1;
     char _date[50]  ="1 Aug 2022";
     while(k)
     {

    printf("\t=================ADV. RESTAURANT=================");
    printf("\n\n 1.Generate Invoice");
    printf("\n 2.Show all Invoice");
    printf("\n 3.search Invoice");
    printf("\n 4.exit");
     
    //printf("\n\n Please select your prefered operatin :\t");

    scanf("%d",&opt);
    printf("\n you have chosen %d",opt);
    fgetc(stdin);
     switch(opt){
        case 1:
        //system("claer");
        printf("\n Please enter the name of customer :\t");
        fgets(ord.customer,50,stdin);
        ord.customer[strlen(ord.customer)-1]=0;
       //printf("%s",ord.customer);
      // char o[50]=strcpy(o,ord.customer);
        strcpy(ord.date,_date);
        printf("\n Please enter number of item:\t");
        scanf("%d",&n); 
        ord.numofitem=n;
        for (int  i = 0; i < n; i++)
        {
             fgetc(stdin);
             printf("\n\n");
             printf("Please enter the item %d\t",i+1);
             fgets(ord.itm[i].item,20,stdin);
             ord.itm[i].item[strlen(ord.itm[i].item )-1]=0;
             printf("\nPlease enter the Quantity:\t");
             scanf("%d",&ord.itm[i].qty);
             printf("\n Please enter the price :\t");
             scanf("%f",&ord.itm[i].price);
             total+=ord.itm[i].qty*ord.itm[i].price;


        }
        generatebillheader( ord.customer,ord.date);
       // printf("%s",ord.customer);
        for (size_t i = 0; i <ord.numofitem; i++)
        {
            generaterbilllbody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);

            /* code */
        }
        generatebillfoter(total);
        printf("\n Do you want to save the invoice :\t");
        scanf("%s",&savebill);
        if(savebill=='y'){
            fp=fopen("RestaurantBilll.data","a+");
            fwrite(&ord,sizeof(struct orders),1,fp);
        
            if(!fwrite ==0)
            printf("\n Successfully saved ");
            else 
            printf("\n Error saving");
            fclose(fp);

        }
        break;
        case 2:
        fp=fopen("RestaurantBilll.data","r");
        printf("\n ***** Your prevoious Invoices*****");
        while (fread (&order,sizeof(struct orders),1,fp)){
            float tot=0;
            generatebillheader(order.customer,order.date);
            for (int  i = 0; i <order.numofitem; i++)
            {generaterbilllbody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
            tot+=order.itm[i].qty*order.itm[i].price;

                 
            }
            generatebillfoter(tot);


            
        }
        fclose(fp);
        break;
        case 3:
        printf(" \nEnter the Name of customer:\t");
       fgetc(stdin);
        fgets(name,50,stdin);
         fp=fopen("RestaurantBilll.data","r");
        printf("\n ***** Invoice of %s*****",name);
        while (fread (&order,sizeof(struct orders),1,fp)){
            float tot=0;
            if(!strcmp (order.customer,name)){ generatebillheader(order.customer,order.date);
            for (int  i = 0; i <order.numofitem; i++)
            {generaterbilllbody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
            tot+=order.itm[i].qty*order.itm[i].price;

                 
            }
            generatebillfoter(tot);
            invoce=1;

            }
            


            
        }
        if (!invoce){
            printf(" Sorrry the invoice for %s does not exists ",name);
        }
        fclose(fp);
        break;
        case 4:
        printf("\n\t\t BYE BYE:");
        break;
        default:
        printf(" \nSorry invalid option\n\n ");
        break;




        
            }
      printf("\n\n Do you want to perfrom another operation ?[y ==1/n ==0]:\t");
      scanf("%d",&k);

     }

    printf("\n\n");
     

    return 0;
}