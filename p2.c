void macro()
{
        int n, k, i ; // 정수 변수 정의
        float p, f ; // 일단 이항분포값을 넣을 f값 정의
        int array1[] = {5, 10, 20, 20, 20, 20}  ; //n 값에 넣을 배열
        float array2[] = {0.5, 0.5, 0.5, 0.2, 0.3, 0.4} ; //p 값에 넣을 배열
        short array3[6] = {1,2,3,6,7,8} ;
        char file[20] ; //파일 이름 변수 정의
        FILE *fp ;

        for (i = 0 ; i<6 ; i++) { //file 작성 loop
                sprintf(file,"ex-00%d.dat",i+1); // file 이름 작성
                n = array1[i], p = array2[i] ; // n,p값 정의
                fp = fopen(file,"w"); // file 작성

                for (k = 0 ; k<=n ; k++) { //k는 성공회수, n은 실행횟수이므로, k값의 범위는 n을 넘지 못한다.
                        f = (TMath::Factorial(n)/((TMath::Factorial(k))*(TMath::Factorial(n-k))))*pow(p,k)*pow(1-p,n-k); // 이항분포값을 f에 넣음
                        fprintf(fp,"%d %f \n",k,f);
                } // f값을 파일에 넣는 루프 끝.

                fclose(fp) ; //파일 작성 종료

                TGraph *p = new TGraph(file); //그래프 작성

                if (i == 0){
                        p->GetXaxis()->SetLimits(0,20); //그래프 x축 단위 제한
                        p->SetLineColor(array3[i]) ; //각 그래프 별로 색깔 다르게 적용
                        p->Draw();
                }
                if (i != 0){
                        p->SetLineColor(array3[i]);
                        p->Draw("same");
                }


        } //파일 작성 루프 끝

}
