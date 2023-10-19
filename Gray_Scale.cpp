/* FCAI – OOP Programming – 2023 - Assignment 1
 Program Name:				photolab.cpp
 ALhussain Abdo      and ID and Group: 20220878  unknown ,Email: abdohussin026@gmail.com
 Abdulrahman Tarek   and ID and Group: 20221096  unknown ,Email: abdotarek442442@gmail.com
 Hana Ragab Ahmed    and ID and Group: 20221192  unknown ,Email: hanaragab594@gmail.com
 Teaching Assistant:	unknown
 Purpose:Editing the image (bmp)
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"



using namespace std;
unsigned char image[SIZE][SIZE] , image2[SIZE][SIZE];
int n ;
void load_Image( ){ //  load the image
    cout << "=================================\nEnter name for an image : ";
      char imageFileName[100];
   string s ;
   cin >> imageFileName;
   s = imageFileName;
   while (s != "photographer" &&s!= "elephant" && s != "fruit" && s != "crowd" && s != "House" && s!= "mario" && s != "parots" ){
        cout << "Enter the source image correctly : ";
        cin >> imageFileName;
        s = imageFileName;
   }
    strcat ( imageFileName, ".bmp" );
    readGSBMP(imageFileName, image);
}


void saveimage(unsigned char imag[][SIZE]){
    char Name[100];
    cout << "The name which you want to extract the image with : ";
    cin >> Name;
    strcat (Name, ".bmp");
    writeGSBMP(Name, imag);
}


unsigned first[128][128],second[128][128],third[128][128],fourth[128][128];

void Enlarge_First_Quarter (){
    //copying every pexil in the first quarter into a 4 nighbor pixels in the into another image
    int cont_i = 0 , cont_j = 0 ;
    for (int i = 0 ;  i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j ++ ){
            image2[cont_i][cont_j] = image2[cont_i+1][cont_j] = image2[cont_i][cont_j+1] = image2[cont_i+1][cont_j+1] = first[i][j];
            cont_j +=2;
        }
        cont_i+=2;
        cont_j = 0 ;
    }
}
void Enlarge_Second_Quarter (){
    //copying every pexil in the second quarter into a 4 nighbor pixels in the into another image

    int cont_i = 0 , cont_j = 0 ;
    for (int i = 0 ;  i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j ++ ){
            image2[cont_i][cont_j] = image2[cont_i+1][cont_j] = image2[cont_i][cont_j+1] = image2[cont_i+1][cont_j+1] = second[i][j];
            cont_j +=2;
        }
        cont_i+=2;
        cont_j = 0 ;
    }
}
void Enlarge_Third_Quarter (){
    //copying every pexil in the third quarter into a 4 nighbor pixels in the into another image
    int cont_i = 0 , cont_j = 0 ;
    for (int i = 0 ;  i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j ++ ){
            image2[cont_i][cont_j] = image2[cont_i+1][cont_j] = image2[cont_i][cont_j+1] = image2[cont_i+1][cont_j+1] = third[i][j];
            cont_j +=2;
        }
        cont_i+=2;
        cont_j = 0 ;
    }
}
void Enlarge_Fourth_Quarter(){
    //copying every pexil in the fourth quarter into a 4 nighbor pixels in the into another image
    int cont_i = 0 , cont_j = 0 ;
    for (int i = 0 ;  i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j ++ ){
            image2[cont_i][cont_j] = image2[cont_i+1][cont_j] = image2[cont_i][cont_j+1] = image2[cont_i+1][cont_j+1] = fourth[i][j];
            cont_j+=2;
        }
        cont_i+=2;
        cont_j = 0 ;
    }
    
}

void loading_first_querter ( int a , int b  ){
    // a = 128 || 0 , b = 0 || 128
    // copying a quarter of the image into the first quarter of the original image
    int temp = b ;
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++ ){
            image[a][b] = first[i][j];  //
            b++;
        }
        a ++ ;
        b = temp;
    }
}
void loading_second_querter  ( int a , int b ){
    // copying a quarter of the image into the second quarter of the original image
    int temp = b ;
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++ ){
            image[a][b] = second[i][j];  //
            b++;
        }
        a ++ ;
        b = temp;
    }
}
void loading_third_querter (int a, int b){
    // copying a quarter of the image into the third quarter of the original image
    int temp = b ;
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++ ){
            image[a][b] = third[i][j];  //
            b++;
        }
        a ++ ;
        b = temp;
    }
}
void loading_fourth_querter  (int a ,int b ){
    // copying a quarter of the image into the fourth quarter of the original image
    int temp = b ;
    for (int i = 0 ; i < 128 ; i ++ ){
        for (int j = 0 ; j < 128 ; j++ ){
            image[a][b] = fourth[i][j];  //
            b++;
        }
        a ++ ;
        b = temp;
    }
}
    void Black_and_White_Filter (){ // BW
    //checking if the value of the pixel id less than 127 then make it black otherwise make it white
        for (int i = 0 ; i < SIZE ; i++ ){
            for (int j = 0  ; j < SIZE; j++ ){
                if ( image[i][j] > 127)
                    image[i][j] = 255;
                else image[i][j]= 0;
            }
        }
    }
    void Invert_Filter(){
        //changing the pixel value to 255-original pixel value to get the inverse
        for (int i = 0 ; i < SIZE ; i ++ ){
            for (int j = 0 ; j < SIZE ; j++ ){
                image[i][j] = 255-image[i][j];
            }
        }
    }
    void Merge_Filter (){
        //loading the image the user want to merge
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
   readGSBMP(imageFileName, image2);
    //assigning the pixel value to the avrage of the pixels of the two images the user wants to merge
    for (int i = 0 ; i < SIZE ; i++){
        for (int j = 0 ; j<SIZE  ; j++ ){
            image [i][j] = (image2[i][j] + image[i][j])/2;
        }
    }
}
    void Flip_Image (){
        cout << "Do you want to flib the image\n1.horizontally\n2.vertically\nchoos from (1, 2 ) : ";
        int a ;
        cin >> a ;
        unsigned char temp [SIZE][SIZE];
        if ( a == 1 )
        {
            // cppying the pixel of index [i][255-j] of the original image into pexil of value [i][j]in the temp image
            for (int i = 0 ; i < SIZE ; i ++ ){
                for (int j = 0 ; j < SIZE ; j++ ){
                    temp[i][j]=image[i][255-j];
                
                }
            }
        }
        else {
            // cppying the pixel of index [255-i][j] of the original image into pexil of value [i][j]in the temp image

            for (int i = 0 ; i < SIZE ; i ++ ){
                for (int j = 0 ; j < SIZE ; j++ ){
                    temp[i][j]=image[255-i][j];
                    
                }
            }
        }
        // copying the temp image back into the original one
        memcpy(image ,temp , sizeof(temp));
    }
    void Rotate_Image( ){
        int degree;
         cout<<"Rotate (90), (180) or (270) degrees?";
        cin>>degree;
         unsigned char temp [SIZE][SIZE];
        while ( degree != 90 && degree != 180 && degree != 270   )
        {
            cout << "Error: this is a wrong degree\nchoose from\n{90, 180, 270} : ";
            cin >> degree;
        }
        if ( degree == 90){
            //copying the pixel of index [i][j] in the original image into the pexil of index [255-j][i] in the copy image
            int cont_i =  SIZE -1  , cont_j = 0 ;
            for (int i = 0 ; i < SIZE  ; i ++ ){
                for (int j = 0 ; j < SIZE ; j ++ )
                {
                    temp[255-j][i] = image[i][j];
                }
            }

            // for (int i = 0 ; i < SIZE ;i++){
            //     for (int j = 0 ; j < SIZE ; j ++ )
            //     {
            //         image[i][j] = temp[i][j];
            //     }
            // }
        }
        else if ( degree == 180){
            //copying the pixel of index [i][j] in the original image into the pexil of index [255-i][255-j] in the copy image

            for (int i = 0 ; i < SIZE ; i ++ ){
                for (int j = 0 ; j < SIZE ; j ++ ){
                    temp[255-i][255-j] = image[i][j];
                }
            }   
          
        }
        else if ( degree == 270){
            //copying the pixel of index [i][j] in the original image into the pexil of index [j][255-i] in the copy image

            for (int i =0  ; i < SIZE ;i  ++ ) {
                for (int j = 0 ; j < SIZE ; j ++ ){
                    temp[j][255-i] = image[i][j];
                }
            }
          
        }
    // copying the temp image into the original image
    for (int i = 0 ; i < SIZE ;i++){
            for (int j = 0 ; j < SIZE ; j ++ )
            {
                image[i][j] = temp[i][j];
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
            // assigning the pixel value to its half 
            for (int i = 0 ; i < SIZE ; i ++ ){
                for (int j = 0 ; j < SIZE ; j ++ ){
                    image[i][j ] /= 2;
                }
            }
        }
        else {
            for (int i = 0 ; i < SIZE ; i ++ ){
                for (int j = 0 ; j < SIZE ; j ++ ){
                    // adding half of the pixel value to it

                    image[i][j ] += (  255 - image[i][j] ) / 2 ;
                }
            }
        }
    }
    void Detect_Image_Edges  ( ) {
        unsigned char temp[SIZE][SIZE];
        // converting the image to black and white image
        Black_and_White_Filter();
        for (int i = 0 ; i < SIZE -1  ; i ++ ){
            for (int j = 0 ; j < SIZE -1  ; j++ ){
                // checking if the pixel value does not equal the values of the pixels it's srounded by then made it black otherwise make it white
                if  ( image[i][j] != image[i+1][j] && image[i][j] != image[i-1][j] && image[i][j] != image[i][j+1] && image[i][j] != image[i][j-1] && 
                image[i][j] != image[i-1][j-1] && image[i][j] != image[i+1][j+1]  )
                    image[i][j] = 0;   
                else image[i][j] = 255;
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
            // copying the first quarter into a new 128*128 image
            for (int i = 0 ; i < 128 ; i ++ ){
                for (int j = 0 ; j < 128 ; j++){
                    first[i][j] = image[i][j];
                }
            }
            // descriped before
            Enlarge_First_Quarter();
        }
        else if (num == 2){
            // copying the second quarter into a new 128*128 image
            for (int i = 0 ; i < 128 ; i ++){
                for (int j = 128 ; j < SIZE ; j++ ){
                    second[cont_i][cont_j++] = image[i][j];
                }
                cont_i ++;
                cont_j = 0;
            }
            // descriped before
            Enlarge_Second_Quarter();
        }
        else if ( num == 3  ){
            // copying the third quarter into a new 128*128 image
            for (int i = 128 ; i < SIZE ; i++ ){
                for (int j = 0 ; j < 128; j ++  ){
                    third[ cont_i][cont_j++] = image[i][j];
                }
                cont_i ++;
                cont_j = 0 ;
            }
            // descriped before
            Enlarge_Third_Quarter();
        }
        else {
            // copying the forth quarter into a new 128*128 image
            for (int i = 128 ; i < SIZE ; i++ ){
                for (int j = 128 ;  j< SIZE; j ++  ){
                    fourth[ cont_i][cont_j++] = image[i][j];
                }
                cont_i ++;
                cont_j = 0 ;
            }
            // descriped before
            Enlarge_Fourth_Quarter();
        }
        // copying the temp image into the original one
        for (int i = 0 ; i < SIZE ; i ++ ){
            for (int j = 0 ; j < SIZE ;j ++ )
            {
                image[i][j] = image2[i][j];
            }
        }
    }
    void Shrink_Image (  ){
        unsigned char copy[SIZE][SIZE];
        int cont_i =  0, cont_j = 0 ;
        for (int i = 0 ; i < SIZE ;i ++ ){
            for (int j = 0 ; j < SIZE ; j++ ){
                copy[i][j] = 255;
            }
        }
        cout << "Shrink to 1.(1/2), 2.(1/3), 3.(1/4)?\nchoose from (1:3) : ";
        int a ;
        cin >> a ;
        if ( a == 1 ){
            for (int i = 0 ; i+ 2  < SIZE ; i+=2   ){
                for (int j = 0 ; j + 2  < SIZE ; j +=2  ) {
                    // copying the avrage of a four nighbours pixels in the origirnl image and copy it into one pixel in the temp image
                    int avg ;
                    avg = ( image[i][j] + image[i][j+1] + image[i+1][j] + image[i+1][j+1]   );
                    avg /= 4;
                    copy[cont_i][cont_j++] = avg;
                }
                cont_i ++;
                cont_j = 0 ;
            }

        }
        else if ( a == 2 ){
            for (int i = 0 ; i+ 3  < SIZE ; i+=3   ){
                for (int j = 0 ; j + 3  < SIZE ; j +=3  ) {
                    // copying the avrage of a 9 nighbours pixels in the origirnl image and copy it into one pixel in the temp image

                    int avg ;
                    avg = ( image[i][j] + image[i][j+1] + image[i][j+2 ] + image[i+1][j] + image[i+1][j+1] + image[i+1][j+2] +
                            image[i+2][j] + image[i+2][j+1] + image[i+2][j+2 ] );
                    avg /= 9;
                    copy[cont_i][cont_j++] = avg;
                }
                cont_i ++;
                cont_j = 0 ;
            }

        }
        else {
            for (int i = 0 ; i+ 4  < SIZE ; i+=4   ){
                for (int j = 0 ; j + 4  < SIZE ; j +=4  ) {
                    // copying the avrage of a 16 nighbours pixels in the origirnl image and copy it into one pixel in the temp image

                    int avg ;
                    avg = ( image[i][j] + image[i][j+1] + image[i][j+2 ] + image[i][j+3] +  image[i+1][j] + image[i+1][j+1] + image[i+1][j+2] + image[i+1][j+3] +
                            image[i+2][j] + image[i+2][j+1] + image[i+2][j+2 ] + image[i+2][j+3] +image[i+3][j] + image[i+3][j+1] + image[i+3][j+2 ] + image[i+3][j+3] );
                    avg /= 16;
                    copy[cont_i][cont_j++] = avg;
                }
                cont_i ++;
                cont_j = 0 ;
            }
        }
        for (int i = 0 ; i  <  SIZE  ; i++ ){
            for (int j = 0 ; j < SIZE ; j ++ ){
                image[i][j] = copy[i][j];
            }
        }
    }
    void Mirror_Image (  ){
        cout << "Do you want to mirror the image\n{1.Left, 2.Right, 3.Upper, 4.Lower}\nchoose from (1:4) : ";
        int a ;
        cin >> a ;
        if ( a == 1 ){
            for (int i = 0 ; i < SIZE ;  i ++ ){
                // copying the fliped left sideof the image into the right side of it
                for (int j = 0 ; j < 128 ; j ++ ){
                    image[i][255-j] = image[i][j];
                }
            }
        }
        if ( a == 2 ){
                // copying the fliped right sideof the image into the left side of it

            for (int i = 0 ; i<SIZE ;  i ++ ){
                for (int j = 128 ; j<SIZE ; j ++ ){
                    image[i][255-j] = image[i][j];
                }
            }
        }
        if (a == 3 ){
                // copying the fliped upper sideof the image into the lower side of it

            for (int i = 0 ; i < 128 ; i ++ ){
                for (int j = 0 ; j < SIZE ; j++){
                    image[255- i][j] = image[i][j];
                }
            }
        }
        if ( a == 4 ){
                // copying the fliped lower sideof the image into the upper side of it

            for (int i = 128 ; i < SIZE ; i ++ ){
                for (int j = 0 ; j < SIZE ; j++){
                    image[ 255- i ][j] = image[i][j];
                }
            }
        }
    }
    void Shuffle_Image ( ){
        unsigned copy[SIZE][SIZE];
        for (int i = 0 ; i < 128 ; i ++ ){
            // copying the first quarter into a new 128*128 image
            for (int j = 0 ; j < 128 ; j++){
                first[i][j] = image[i][j];
            }
        }
        int cont_i = 0 , cont_j = 0 ;
        for (int i = 0 ; i < 128 ; i ++){
            for (int j = 128 ; j < SIZE ; j++ ){
            // copying the second quarter into a new 128*128 image
                second[cont_i][cont_j++] = image[i][j];
            }
            cont_i ++;
            cont_j = 0;
        }
        cont_i = 0 ; cont_j = 0 ;
        for (int i = 128 ; i < SIZE ; i++ ){
            for (int j = 0 ; j < 128; j ++  ){
            // copying the third quarter into a new 128*128 image
                third[ cont_i][cont_j++] = image[i][j];
            }
            cont_i ++;
            cont_j = 0 ;
        }
        cont_i = 0 ; cont_j = 0 ;
        for (int i = 128 ; i < SIZE ; i++ ){
            for (int j = 128 ;  j< SIZE; j ++  ){
                // copying the fourth quarter into a new 128*128 image
                fourth[ cont_i][cont_j++] = image[i][j];
            }
            cont_i ++;
            cont_j = 0 ;
        }
        cont_i= 0 ,cont_j = 0 ;
        cout << "which order do you want to print the quarters\nselect four number (the order) between (1:4)\n(NOTE :tap space between each one: ";
        int a , b , c , d ;
        cin >> a >> b >> c  >> d ;
        cont_i = 0 , cont_j = 0 ;
        // copying the quarters into the originals image in a new image depending on the user input
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
    void Blur_Image(){
        // assigning the pexil value to the avrage of it ans the 5 pexils around it 4 times
        for (int i = 0; i < 255; i++)
        {
            for (int j = 0; j < 255; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    image[i][j]=((image[i][j]+image[i+k][j]+image[i][j+k]+image[i+k][j+k]+image[i-k][j]+image[i][j-k])/6);
                    
                }
                
               

            }
            
        }
    
}
    void Crop_Image(){
        int x , y , length,width;
        cout << "Enter x y length width : ";
        cin >> x >> y >> length >> width;
        // making the pixels out of range white
        for (int i = 0 ; i < SIZE; i ++ ){
            for (int j = 0 ; j < SIZE ; j ++ ){
                if ( i < x )
                    image[i][j] = 255;
                if ( i > x + length)
                    image[i][j] = 255;
                if ( j < y)
                    image[i][j] = 255;
                if (j > j+ width)
                    image[i][j] = 255;
            }
        }
    }
    // the skew filters:The User determines the degree of the skew we loop on the image, and get the side opposite to the angle (by multiplying the tan of the angle with the adjacent side), and set them to white, so now we have to white triangles, we compress the remaining parts (that are not white).
    // descriped by details in the PDF
    void Skew_Image_Right(){
        cout << "Enter the degree: ";
        float deg;
        cin >> deg;
        while ( deg >= 45 ){
        cout << "Error :: this is wrong degree choos from ]0:45[ : ";
        cin >>deg;
    }
        unsigned char copy[SIZE][SIZE];
        for(int i = 0 ; i < SIZE ; i++ ){
            for (int j = 0 ; j < SIZE ; j ++ ){
                copy[i][j] = 255;
            }
        }
        int a = 1 , b = 256;
        double pi = 22/7.0;
        for( int i = 0 ; i < SIZE ; i ++ , b-- , a ++ ){
            int leftTriangleSide = ( tan (deg * ( pi / 180.0))*b);
            int rightTriangleSide = (tan(deg * (pi/180.0))*a);
            double pixels = ( 256- (leftTriangleSide + rightTriangleSide ) );
            pixels =  256.0/pixels; // 1.2 //==> 1 ===> 0.2 REMINDER = 0.2 ,,,  1.2 + 0.2 ==> 1.4 ==> 2.4 ==>  2 ===>  2.4 ==> r = 0.4
            double a = pixels , remainder = 0 ;
            int j = leftTriangleSide;
            for (int k = 0 ; k < SIZE ; k+= floor ( pixels + remainder)){
                int avg = 0 ;
                for (int w = 0 ; w < floor(pixels + remainder ) ; w++ ){
                    avg += image[i][w+k];
                }
                avg /= floor( pixels + remainder );
                if ( j > 256-rightTriangleSide){
                    break;
                }
                copy[i][j++] = avg; // 2.4   ..   2 <  3.2   ,, 0.6
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
                image[i][j] = copy[i][j];
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
        unsigned char copy[SIZE][SIZE];
        for(int i = 0 ; i < SIZE ; i++ ){
            for (int j = 0 ; j < SIZE ; j ++ ){
                copy[i][j] = 255;
            }
        }
        int a = 1 , b = 256;
        double pi = 22/7.0;
        for( int i = 0 ; i < SIZE ; i ++ , b-- , a ++ ){
                int leftTriangleSide = ( tan (deg * ( pi / 180.0))*b);
                int rightTriangleSide = (tan(deg * (pi/180.0))*a);
                double pixels = ( 256- (leftTriangleSide + rightTriangleSide) );
                pixels =  256.0/pixels;
                double a = pixels , remainder = 0 ;
                int j = leftTriangleSide;
                for (int k = 0 ; k < SIZE ; k+= floor ( pixels + remainder)){
                     int avg = 0 ;
                    for (int w = 0 ; w < floor(pixels + remainder ) ; w++ ){
                        avg += image[w+k][i];
                    }
                    avg /= floor( pixels + remainder );
                    if ( j > 256-rightTriangleSide){
                        break;
                    }
                    copy[j++][i] = avg; // 2.4   ..   2 <  3.2   ,, 0.6
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
                image[i][j] = copy[i][j];
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
        else if( ch == 'c')
            Blur_Image();
        else if ( ch =='d')
            Crop_Image();
        else if ( ch == 'e')
            Skew_Image_Right();
        else if ( ch == 'f')
            Skew_Image_Up();
        else if (ch == 's')
            saveimage(image) ;
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