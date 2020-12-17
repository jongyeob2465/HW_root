void macro()
{
        int ramda, n, i ;
        double f ;
        int array[6] = {1,5,10,20,50,100} ; //람다에 넣을 값을 리스트로 작성
        char file[20];
        FILE *fp ;

        for (i = 0 ; i<6 ; i++){
        ramda = array[i] ; //람다에 값을 넣음
        sprintf(file,"ex-00%d.dat",i+1); //for 루프마다 만들 file의 이름
        fp = fopen(file,"w"); //파일 작성

        for (n=0 ; n<=100 ; n++){
                f =(pow(ramda,n)*pow(TMath::Exp(1),-ramda))/(TMath::Factorial(n)) ; //람다값과 n값을 지정한 뒤 푸아송 값 계산
                fprintf(fp,"%d %lf \n",n,f); //n값과 푸아송 값 입력
        }
        fclose(fp); // 파일 닫음
        }
}

//gnuplot
////plot "ex-001.dat"
////replot "ex-002.dat"
////replot "ex-003.dat"
////....
