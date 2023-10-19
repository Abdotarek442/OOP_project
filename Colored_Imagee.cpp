/* FCAI – OOP Programming – 2023 - Assignment 1
 Program Name:				photolab.cpp
 Last Modification Date:	05/10/2023
 ALhussain Abdo      and ID and Group: 20220878  unknown
 Abdulrahman Tarek   and ID and Group: 20221096  unknown
 Hana Ragab Ahmed    and ID and Group: 20221192  unknown
 Teaching Assistant:	unknown
 Purpose:..........
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"


using namespace std;
unsigned char image[SIZE][SIZE][RGB] , image2[SIZE][SIZE][RGB] ,copy[SIZE][SIZE][RGB];
unsigned first_quarter[128][128][RGB],second_quarter[128][128][RGB],third_quarter[128][128][RGB],fourth_quarter[128][128][RGB];
int n ;

//----------------------------------------------------------------------------------------------------------------

void load_Image( ){ //  load the image
    cout << "=================================\nEnter name for an image : ";
      char imageFileName[100];
   string s ;
   cin >> imageFileName;
   s= imageFileName;
   while (s != "photographer" &&s!= "elephant" && s != "fruit" && s != "crowd" && s != "House" && s!= "mario" && s != "parots" ){
        cout << "Enter the source image correctly : "; // if the user gives us wrong input 
        cin >> imageFileName;
        s = imageFileName;
   }
    strcat ( imageFileName, ".bmp" );
    readRGBBMP(imageFileName, image);
}


void saveimage(unsigned char imag[][SIZE][RGB]){ // saving an image 
    char Name[100];
    cout << "The name which you want to extract the image with : ";
    cin >> Name;
    strcat (Name, ".bmp");
    writeRGBBMP(Name, imag);
}

void Enlarge_First_Quarter (){
    int cont_i = 0 , cont_j = 0 ;
    for (int i = 0 ;  i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j ++ ){
            for (int k =0  ; k < RGB ; k ++ ){
                 image2[cont_i][cont_j][k]   =  first_quarter[i][j][k];
                 image2[cont_i+1][cont_j][k]  =  first_quarter[i][j][k];
                 image2[cont_i][cont_j+1][k]    =  first_quarter[i][j][k];
                 image2[cont_i+1][cont_j+1][k] = first_quarter[i][j][k];
            }
            cont_j +=2;
        }
        cont_i+=2;
        cont_j = 0 ;
    }
}


void Enlarge_Second_Quarter (){
    int cont_i = 0 , cont_j = 0 ;
    for (int i = 0 ;  i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j ++ ){
            for (int k = 0 ; k < RGB ; k++)
              {  image2[cont_i][cont_j][k] = image2[cont_i+1][cont_j][k] = image2[cont_i][cont_j+1][k] = image2[cont_i+1][cont_j+1][k] = second_quarter[i][j][k];}
                cont_j +=2;
        }
        cont_i += 2;
        cont_j = 0 ;
    }
}


void Enlarge_Third_Quarter (){
    int cont_i = 0 , cont_j = 0 ;
    for (int i = 0 ;  i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j ++ ){
            image2[cont_i][cont_j][RGB] = image2[cont_i+1][cont_j][RGB] = image2[cont_i][cont_j+1][RGB] = image2[cont_i+1][cont_j+1][RGB] = third_quarter[i][j][RGB];
            cont_j +=2;
        }
        cont_i+=2;
        cont_j = 0 ;
    }
}


void Enlarge_Fourth_Quarter(){
    int cont_i = 0 , cont_j = 0 ;
    for (int i = 0 ;  i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j ++ ){
            for (int k= 0 ; k < RGB ; k++)
            image2[cont_i][cont_j][k] = image2[cont_i+1][cont_j][k] = image2[cont_i][cont_j+1][k] = image2[cont_i+1][cont_j+1][k] = fourth_quarter[i][j][k];
            cont_j+=2;
        }
        cont_i+=2;
        cont_j = 0 ;
    }
}


void loading_first_querter ( int a , int b  ){
    // a = 128 || 0 , b = 0 || 128
    int temp = b ;
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++ ){
            for (int k = 0 ; k < RGB ; k++)
                image[a][b][k] = first_quarter[i][j][k];  //
            b++;
        }
        a ++ ;
        b = temp;
    }
}


void loading_second_querter  ( int a , int b ){
    int temp = b ;
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++ ){
            for (int k = 0 ; k < RGB ; k++)
                image[a][b][k] = second_quarter[i][j][k];  //
            b++;
        }
        a ++ ;
        b = temp;
    }
}

void loading_third_querter (int a, int b){
    int temp = b ;
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++ ){
            for (int k = 0 ; k < RGB ; k++)
                image[a][b][k] = third_quarter[i][j][k];  //
            b++;
        }
        a ++ ;
        b = temp;
    }
}


void loading_fourth_querter  (int a ,int b ){
    int temp = b ;
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++ ){
            for (int k = 0 ; k < RGB ; k++)
                image[a][b][k] = fourth_quarter[i][j][k];  //
                b++;
        }
        a ++ ;
        b = temp;
    }
}


void Black_and_White_Filter (){ // BW
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int grayScale = (image[i][j][0]+image[i][j][1]+image[i][j][2])/3;
            for (int k = 0; k < RGB; k++)
            {
                if(grayScale>128){
                    image[i][j][k]=255;

                }else{
                    image[i][j][k]=0;

                }
            }
        }
        
    }
}

    void Invert_Filter( ){
        for (int i = 0 ; i < SIZE ; i ++ ){
            for (int j = 0 ; j < SIZE ; j++ ){
                for (int k = 0 ; k < RGB ; k++)
                   image[i][j][k] = 255-image[i][j][k];
            }
        }
    }


void Merge_Filter ( ){
    char imageFileName[100];
    string s ;
    cout << "Enter the source image file name which you want to merge with: ";
    cin >> imageFileName;
    s = imageFileName;
    while (s != "photographer" &&s!= "elephant" && s != "fruit" && s != "crowd" && s != "House" && s!= "mario" && s != "parots" ){
        cout << "Enter the source image correctly : ";
        cin >> imageFileName;
        s = imageFileName;
   }
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image2);
        for (int i = 0 ; i < SIZE ; i++)
        {
            for (int j = 0 ; j<SIZE  ; j++ )
            {
                for (int k = 0 ; k < RGB ; k++)
                     image [i][j][k] = (image2[i][j][k]+ image[i][j][k])/2;
            }
        }
    }


void Flip_Image (){
    cout << "Do you want to flib the image\n1.horizontally\n2.vertically\nchoos from (1, 2 ) : ";
    int a ;
    cin >> a ;
    unsigned char temp [SIZE][SIZE][RGB];
    if ( a == 1 )
    {
        for (int i = 0 ; i < SIZE ; i ++ ){
            for (int j = 0 ; j < 128 ; j++ ){
                for (int k = 0 ; k < RGB ; k++){
                    temp[i][j][k] = image[i][j][k];
                    image[i][j][k] = image[i][255-j][k];
                    image[i][255-j][k] = temp[i][j][k];
                }
            }
        }
    }
    else {
        for (int i = 0 ; i < SIZE ; i ++ ){
            for (int j = 0 ; j < 128 ; j++ ){
                for (int k = 0 ; k < RGB ; k++ ){
                    temp[j][i][k] = image[j][i][k];
                    image[j][i][k] = image[255 - j ][i][k];
                    image[255-j][i][k] = temp[j][i][k];
                }
        }
        }
    }
}


void Rotate_Image( ){
    int degree;
        cout<<"Rotate (90), (180) or (270) degrees? ";
    cin>>degree;
        unsigned char temp [SIZE][SIZE][RGB];
    while ( degree != 90 && degree != 180 && degree != 270   )
    {
        cout << "Error: this is a wrong degree\nchoose from\n{90, 180, 270} : ";
        cin >> degree;
    }
    if ( degree == 90){
        int cont_i =  SIZE -1  , cont_j = 0 ;
        for (int i = 0 ; i < SIZE  ; i ++ ){
            for (int j = 0 ; j < SIZE ; j ++ )
                for (int k = 0 ; k < RGB ; k++)    
                {
                    temp[255-j][i][k] = image[i][j][k];
                }
        }
        
    }
    else if ( degree == 180){
        for (int i = 0 ; i < SIZE ; i ++ ){
            for (int j = 0 ; j < SIZE ; j ++ ){
                for (int k =0 ; k < RGB ; k++ )
                        temp[255-i][255-j][k] = image[i][j][k];
            }
        }   
        
    }
    else if ( degree == 270){
        for (int i =0  ; i < SIZE ;i  ++ ) {
            for (int j = 0 ; j < SIZE ; j ++ ){
                for (int k = 0 ; k < SIZE ; k++ )
                    temp[j][255-i][k] = image[i][j][k];
            }
        }
        
    }
    for (int i = 0 ; i < SIZE ;i++){
        for (int j = 0 ; j < SIZE ; j ++ )
            for (int k =0 ; k < RGB ;k ++)
            {
                image[i][j][k] = temp[i][j][k];
            }
    }
}


void Darken_And_Lighten_Image(  ){
    cout << "Do you want it\n1.Darken\n2.lighten\nchoose from (1,2) : ";
    int a ;
    cin >> a ;
    while ( a != 1 && a != 2 )
    {
        cout << "Error: wrong input\nchoose from ( 1, 2 ) : ";
        cin >> a ;
    }
    if ( a == 1 )
    {
        for (int i = 0 ; i < SIZE ; i ++ ){
            for (int j = 0 ; j < SIZE ; j ++ ){
                for (int k = 0 ; k < RGB ; k++ )
                        image[i][j ][k] /= 2;
            }
        }
    }
    else {
        for (int i = 0 ; i < SIZE ; i ++ ){
            for (int j = 0 ; j < SIZE ; j ++ ){
                for (int k = 0 ; k < RGB ; k++ )
                        image[i][j ][k] += (  255 - image[i][j][k] ) / 2 ;
            }
        }
    }
}


void Detect_Image_Edges  ( ) {
      unsigned char copy[SIZE][SIZE][RGB];
    Black_and_White_Filter(); // for image[SIZE[SIZE][RGB]
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                if(image[i][j][k]!=image[i+1][j+1][k]){
                    copy[i][j][k]=0;
                }   
                else{
                    copy[i][j][k]=255;
                }
            }
        }    
    }
    for (int i = 0 ; i < SIZE ; i ++ ){
        for (int j =0 ; j < SIZE ; j ++ ){
            for (int k = 0 ; k  < RGB ; k ++ )
                image[i][j][k] = copy[i][j][k];
        }
    }

}
void Enlarge_Image () {
    int num;
    cout <<"Which quarter to enlarge : {1, 2, 3, 4} : ";
    cin >> num ;
    while (num != 1 && num != 2 && num !=3 && num != 4){
        cout << "Error : Wrong input\nchoose from (1, 2, 3, 4) : ";
        cin >> num;
    }
    
    int cont_i = 0 , cont_j = 0 ;
        
    if (num == 1  ){
        for (int i = 0 ; i < 128 ; i ++ ){
            for (int j = 0 ; j < 128 ; j++){
                for (int k = 0 ; k < RGB ; k++ ) {
                    first_quarter[i][j][k] = image[i][j][k];
                }
            }
        }
        Enlarge_First_Quarter();
    }
    else if (num == 2){
        for (int i = 0 ; i < 128 ; i ++){
            for (int j = 128 ; j < SIZE ; j++ ){
                for (int k = 0 ; k < RGB ; k++ )
                    second_quarter[cont_i][cont_j][k] = image[i][j][k];
                    cont_j++;
            }
            cont_i ++;
            cont_j = 0;
        }

        Enlarge_Second_Quarter();
    }
    else if ( num == 3  ){
        for (int i = 128 ; i < SIZE ; i++ ){
            for (int j = 0 ; j < 128; j ++  ){
                for (int k = 0 ; k < RGB ; k++ )
                    third_quarter[ cont_i][cont_j][k]= image[i][j][k];
                    cont_j++;
            }
            cont_i ++;
            cont_j = 0 ;
        }
        Enlarge_Third_Quarter();
    }
    else {
        for (int i = 128 ; i < SIZE ; i++ ){
            for (int j = 128 ;  j< SIZE; j ++  ){
                for (int k = 0 ; k < RGB ; k++ )
                    fourth_quarter[ cont_i][cont_j][k] = image[i][j][k];
                    cont_j++;
            }
            cont_i ++;
            cont_j = 0 ;
        }
        Enlarge_Fourth_Quarter();
    }
    for (int i = 0 ; i < SIZE ; i ++ ){
        for (int j = 0 ; j < SIZE ;j ++ )
        {
            for (int k = 0 ; k < RGB ; k++ )
                image[i][j][k] = image2[i][j][k];
        }
    }
}


void Shrink_Image (  ){
    unsigned char copy[SIZE][SIZE][RGB];
    int cont_i =  0, cont_j = 0 ;
    for (int i = 0 ; i < SIZE ;i ++ ){
        for (int j = 0 ; j < SIZE ; j++ ){
            for (int k = 0 ; k < RGB ; k++ )
                copy[i][j][k] = 255;
        }
    }
    cout << "Shrink to 1.(1/2), 2.(1/3), 3.(1/4)?\nchoose from (1:3) : ";
    int a ;
    cin >> a ;
    if ( a == 1 ){
        for (int i = 0 ; i < SIZE ; i+=2   ){
            for (int j = 0 ; j  < SIZE ; j +=2  ) {
                for (int k = 0 ; k < RGB ; k++ ){
                    int avg ;
                    avg = ( image[i][j][k] + image[i][j+1][k] + image[i+1][j][k] + image[i+1][j+1][k]  );
                    avg /= 4;
                    copy[cont_i][cont_j][k]= avg;
                }
                cont_j++;
            }
            cont_i ++;
            cont_j = 0 ;
        }

    }
    else if ( a == 2 ){
        for (int i = 0 ; i+ 3  < SIZE ; i += 3   ){
            for (int j = 0 ; j + 3  < SIZE ; j += 3  ) {
                for (int k = 0 ; k < RGB ; k++ )
                { 
                    int avg ;
                    avg = ( image[i][j][k] + image[i][j+1][k] + image[i][j+2 ][k] + image[i+1][j][k] + image[i+1][j+1][k] + image[i+1][j+2][k] +
                            image[i+2][j][k] + image[i+2][j+1][k] + image[i+2][j+2 ][k] );
                    avg /= 9;
                    copy[cont_i][cont_j][k] = avg;
                    }
                    cont_j++;
            }
            cont_i ++;
            cont_j = 0 ;
        }

    }
    else {
        for (int i = 0 ; i+ 4  < SIZE ; i+=4   ){
            for (int j = 0 ; j + 4  < SIZE ; j +=4  ) {
                for (int k = 0 ; k < RGB ; k++ ){
                    int avg ;
                    avg = ( image[i][j][k] + image[i][j+1][k] + image[i][j+2 ][k] + image[i][j+3][k] +  image[i+1][j][k] + image[i+1][j+1][k] + image[i+1][j+2][k] + image[i+1][j+3][k] +
                            image[i+2][j][k] + image[i+2][j+1][k] + image[i+2][j+2 ][k] + image[i+2][j+3][k] +image[i+3][j][k] + image[i+3][j+1][k] + image[i+3][j+2 ][k] + image[i+3][j+3][k] );
                    avg /= 16;
                    copy[cont_i][cont_j][k] = avg;
                }
                cont_j++;

            }
            cont_i ++;
            cont_j = 0 ;
        }
    }
    for (int i = 0 ; i  <  SIZE  ; i++ ){
        for (int j = 0 ; j < SIZE ; j ++ ){
            for (int k = 0 ; k < RGB ; k++ )
                image[i][j][k] = copy[i][j][k];
        }
    }
}


void Mirror_Image (  ){
    cout << "Do you want to mirror the image\n{1.Left, 2.Right, 3.Upper, 4.Lower}\nchoose from (1:4) : ";
    int a ;
    cin >> a ;
    if ( a == 1 ){
        for (int i = 0 ; i < SIZE ;  i ++ ){
            for (int j = 0 ; j < 128 ; j ++ ){
                for (int k = 0 ; k < RGB ; k++ )
                    image[i][255-j][k] = image[i][j][k];
            }
        }
    }
    if ( a == 2 ){
        for (int i = 0 ; i<SIZE ;  i ++ ){
            for (int j = 128 ; j<SIZE ; j ++ ){
                for (int k = 0 ; k < RGB ; k++ )
                    image[i][255-j][k]= image[i][j][k];
            }
        }
    }
    if (a == 3 ){
        for (int i = 0 ; i < 128 ; i ++ ){
            for (int j = 0 ; j < SIZE ; j++){
                for (int k = 0 ; k < RGB ; k++ )
                    image[255- i][j][k] = image[i][j][k];
            }
        }
    }
    if ( a == 4 ){
        for (int i = 128 ; i < SIZE ; i ++ ){
            for (int j = 0 ; j < SIZE ; j++){
                for (int k = 0 ; k < RGB ; k++ )
                    image[ 255- i ][j][k] = image[i][j][k];
            }
        }
    }
}


void Shuffle_Image ( ){
    unsigned copy[SIZE][SIZE][RGB];
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++){
            for (int k = 0 ; k < RGB ; k++ )
                first_quarter[i][j][k] = image[i][j][k];
        }
    }
      int cont_i = 0 , cont_j = 0 ;
        for (int i = 0 ; i < 128 ; i ++){
            for (int j = 128 ; j < SIZE ; j++ ){
                for (int k =0  ; k < RGB ; k++)
                     second_quarter[cont_i][cont_j][k] = image[i][j][k];
                cont_j ++;
            }
            cont_i ++;
            cont_j = 0;
        }
    cont_i = 0 ; cont_j = 0 ;
    for (int i = 128 ; i < SIZE ; i++ ){
        for (int j = 0 ; j < 128; j ++  ){
            for (int k = 0 ; k < RGB ; k++ )
                third_quarter[ cont_i][cont_j][k] = image[i][j][k];
                cont_j++;
        }
        cont_i ++;
        cont_j = 0 ;
    }
    cont_i = 0 ; cont_j = 0 ;
    for (int i = 128 ; i < SIZE ; i++ ){
        for (int j = 128 ;  j< SIZE; j ++  ){
            for (int k = 0 ; k < RGB ; k++ )
                fourth_quarter[ cont_i][cont_j][k] = image[i][j][k];
                    cont_j++;
        }
        cont_i ++;
        cont_j = 0 ;
    }
    cont_i= 0 ,cont_j = 0 ;
    cout << "which order do you want to print the quarters\nselect four number (the order) between (1:4)\n(NOTE :tap space between each one: ";
    int a , b , c , d ;
    cin >> a >> b >> c  >> d ;
    cont_i = 0 , cont_j = 0 ;
    if ( a == 1 )
    {
        cont_i = 0 , cont_j = 0 ;
        loading_first_querter ( cont_i, cont_j);
    }
    else  if ( a == 2 )
    {
        cont_i = 0 , cont_j = 0 ;
        loading_second_querter ( cont_i, cont_j);
    }
    else  if ( a == 3 )
    {
        cont_i = 0 , cont_j = 0 ;
        loading_third_querter( cont_i, cont_j);
    }
    else  if ( a == 4 )
    {
        cont_i = 0 , cont_j = 0 ;
        loading_fourth_querter ( cont_i, cont_j);
    }
    if ( b == 1 )
    {
        cont_i = 0 , cont_j = 128;
        loading_first_querter (cont_i,cont_j);
    }
    else  if ( b == 2 )
    {
        cont_i = 0 , cont_j = 128;
        loading_second_querter (cont_i,cont_j);
    }
    else  if ( b == 3 )
    {
        cont_i = 0 , cont_j = 128;
        loading_third_querter (cont_i,cont_j);
    }
    else  if ( b == 4 )
    {
        cont_i = 0 , cont_j = 128;
        loading_fourth_querter (cont_i,cont_j);
    }
    if ( c == 1 )
    {
        cont_i = 128 , cont_j = 0;
        loading_first_querter (cont_i,cont_j);
    }
    else if ( c == 2 )
    {
        cont_i = 128 , cont_j = 0;
        loading_second_querter (cont_i,cont_j);
    }
    else  if ( c == 3 )
    {
        cont_i = 128 , cont_j = 0;
        loading_third_querter (cont_i,cont_j);
    }
    else  if ( c == 4 )
    {
        cont_i = 128 , cont_j = 0;
        loading_fourth_querter(cont_i,cont_j);
    }
    if ( d == 1 )
    {
        cont_i = 128 , cont_j = 128;
        loading_first_querter (cont_i,cont_j);
    }
    else  if ( d == 2 )
    {
        cont_i = 128, cont_j = 128;
        loading_second_querter (cont_i,cont_j);
    }
    else  if ( d == 3  )
    {
        cont_i = 128 , cont_j = 128;
        loading_third_querter(cont_i,cont_j);
    }
    else  if ( d == 4 )
    {
        cont_i = 128 , cont_j = 128;
        loading_fourth_querter (cont_i,cont_j);
    }
}


void Blur_Image () {
    for(int i=0;i<SIZE ;i++)
{
        for (int j=0;j<SIZE;j++)
        {
             for (int k = 0; k < 4; k++)
                {
                    for (int l = 0; l < RGB; l++)
                    {
                        image[i][j][l]=((image[i][j][l]+image[i+k][j][l]+image[i][j+k][l]+image[i+k][j+k][l]+image[i-k][j][l]+image[i][j-k][l])/6);
                        
                    }
                    
                }
        }
    }
}


void Crop_Image(){
    int x , y , length,width;
    cout << "Enter x y length width : ";
    cin >> x >> y >> length >> width;
    for (int i = 0 ; i < SIZE; i ++ )
    {
        for (int j = 0 ; j < SIZE ; j ++ )
        {
                for (int k = 0 ; k < RGB ; k++)
                {
                    if((j<x||j>x+length)||i<y||i>x+width)
                            image[i][j][k]=255;
                }
        }
    }
}

void Skew_Image_Up(){
    cout << "Enter the degree: ";
    float deg;
    cin >> deg;
    while ( deg >= 45 ){
        cout << "Error :: this is wrong degree choos from ]0:45[ : ";
        cin >>deg;
    }
    unsigned char copy[SIZE][SIZE][RGB];
    for(int i = 0 ; i < SIZE ; i++ ){
        for (int j = 0 ; j < SIZE ; j ++ ){
            for (int z = 0 ; z< RGB ; z++)
            copy[i][j][z] = 255;
        }
    }
    int a = 1 , b = 256;
    double pi = 22/7.0;
    for( int i = 0 ; i < SIZE ; i ++ , b-- , a ++ ){
            int leftTriangleSide = ( tan (deg * ( pi / 180.0))*b);
            int rightTriangleSide = (tan(deg * (pi/180.0))*a);
            double pixels = ( 256- (leftTriangleSide + rightTriangleSide ) );
            pixels =  256.0/pixels;
            double a = pixels , remainder = 0 ;
            int j = leftTriangleSide;
            for (int k = 0 ; k < SIZE ; k+= floor ( pixels + remainder)){
                int R = 0 , G = 0 , B = 0 ;
                for (int w = 0 ; w < floor(pixels + remainder ) ; w++ ){
                        R += image[k+w][i][0];
                        G += image[k+w][i][1];
                        B += image[k+w][i][2];
                    }

                R  /= floor( pixels + remainder );
                B  /= floor( pixels + remainder );
                G  /= floor( pixels + remainder );

                if ( j > 256-rightTriangleSide){
                    break;
                }

                copy[j][i][0] = R;
                copy[j][i][1] = G;
                copy[j][i][2] = B;  
                j++;
                if (  floor ( pixels) <floor ( pixels + remainder) ) // 3 ==>  3.2 ==> 2.4
                {
                    remainder -= ( floor(pixels + remainder)  - pixels );
                }
                else {
                    remainder += pixels - floor(pixels);
                }
                }
        }
    for (int i = 0 ; i < SIZE ; i ++ ){
        for (int j =0  ; j < SIZE ; j ++ )
            for (int z = 0 ; z< RGB ; z++)
            image[i][j][z] = copy[i][j][z];
    }
}



void Skew_Image_Right(){
    cout << "Enter the degree: ";
    float deg;
    cin >> deg;
    while ( deg >= 45 ){
        cout << "Error :: this is wrong degree choos from ]0:45[ : ";
        cin >>deg;
    }
    unsigned char copy[SIZE][SIZE][RGB];
    for(int i = 0 ; i < SIZE ; i++ ){
        for (int j = 0 ; j < SIZE ; j ++ ){
            for (int z = 0 ; z< RGB ; z++)
            copy[i][j][z] = 255;
        }
    }
    int a = 1 , b = 256;
    double pi = 22/7.0;
    for( int i = 0 ; i < SIZE ; i ++ , b-- , a ++ ){
            int leftTriangleSide = ( tan (deg * ( pi / 180.0))*b);
            int rightTriangleSide = (tan(deg * (pi/180.0))*a);
            double pixels = ( 256- (leftTriangleSide + rightTriangleSide ) );
            pixels =  256.0/pixels;
            double a = pixels , remainder = 0 ;
            int j = leftTriangleSide;
            for (int k = 0 ; k < SIZE ; k+= floor ( pixels + remainder)){
                int R = 0 , G = 0 , B = 0 ;
                for (int w = 0 ; w < floor(pixels + remainder ) ; w++ ){
                        R += image[i][k+w][0];
                        G += image[i][k+w][1];
                        B += image[i][k][2];
                    }

                R  /= floor( pixels + remainder );
                B  /= floor( pixels + remainder );
                G  /= floor( pixels + remainder );

                if ( j > 256-rightTriangleSide){
                    break;
                }

                copy[i][j][0] = R;
                copy[i][j][1] = G;
                copy[i][j][2] = B;  

                j++;
                if (  floor ( pixels) <floor ( pixels + remainder) ) // 3 ==>  3.2 ==> 2.4
                {
                    remainder -= ( floor(pixels + remainder)  - pixels );
                }
                else {
                    remainder += pixels - floor(pixels);
                }
                }
        }
    for (int i = 0 ; i < SIZE ; i ++ ){
        for (int j =0  ; j < SIZE ; j ++ )
            for (int z = 0 ; z< RGB ; z++)
            image[i][j][z] = copy[i][j][z];
    }
}


void menu (){
    char ch ;
    ch = 'l';
    while ( ch != '0')
    {
        cout << "\nWhich filter do you want to implement , Choose from the menu from ( 1 to 14)-or exit\n(NOTE : if you want to save the image press (s) )\n =================================\n";
        cout << "1-Black and White\n2-Invert Image\n3-Merge Images\n4-Flip Image\n5-Rotate Image\n6-Darken and Lighten Image\n7-Detect Image Edges\n8-Enlarge Image\n9-Shrink Image\na-Mirror Image\nb-Shuffle Image\nc-Blur Image \nd-Crop Image\ne-Skew Image Right\nf-Skew Image Up\ns-Save the image to a file\n0.exit\n=================================\n";
        cin >> ch ;
        if ( ch == '1')
            Black_and_White_Filter();
        else if ( ch == '2')
            Invert_Filter();
        else if (ch == '3')
            Merge_Filter();
        else if ( ch == '4')
            Flip_Image();
        else if ( ch == '5')
            Rotate_Image();
        else if ( ch == '6')
           Darken_And_Lighten_Image();
        else if ( ch == '7')
            Detect_Image_Edges();
        else if (ch == '8')
            Enlarge_Image();
        else if (ch == '9')
            Shrink_Image();
        else if ( ch == 'a')
            Mirror_Image();
        else if (ch == 'b')
            Shuffle_Image();
        else if (ch == 'c')
            Blur_Image();
        else if( ch == 'd')
            Crop_Image();
        else if ( ch == 'e')
            Skew_Image_Right();
        else if ( ch == 'f')
            Skew_Image_Up();
        else if ( ch == 's')
            saveimage(image);
        else
            cout<<"filter does not exist,please try again\n";
    }
}
int main()
{
    load_Image();
    menu();
    return 0;
}