void myrm(filesys *fs, directory *rootdir){
  int i = 0, j = 0, a = 0, b=0, c = 0, inodenum, cnt=0;//for문을 위한 변수들, inodenum는 아이노드 번호 저장    
  char minidata_tmp[16][8], temp[10], temp2[10], inodenum_s[5];//minidata_tmp : minidata를 저장, inodenum_s : inodenum atoi 사용   
  int cnt_1=0;                                                //file 길이  
  int num = 0;    char fd;                                                    //'f' => file, '-' =>directory  
  directory *head = rootdir;   
  while(1){                                                   //파일명을 temp에 저장      
    if(ptr[1][a] == '\0'){  
      break;        
      } 
      else if(ptr[1][a] == '/'){  
        break;
        }     
      else 
        temp[a] = ptr[1][a];
      a++;
      } 
    temp[a]='\0';
    cnt_1 = strlen(temp);  
    a = 0;    
    for(i=0;i<16;i++){  
    //minidata를 minidata_tmp로 복사    
    for(j=0;j<8;j++){
     minidata_tmp[i][j] = fs->datablock[head->datablocknum].minidata[i][j];  
     if(minidata_tmp[i][j]=='\0')     
     break;    
     } 
     }
     for(i = 0;i<16;i++){   
     minidata_tmp[i][cnt_1] = '\0';  
     }    
     for(j=0;j<16;j++){   
     if(strcmp(temp,minidata_tmp[j])==0){     
     num=j;  
     break; 
     }
     } 
     while(1){     
     //inode num 복사 
     inodenum_s[b] = fs->datablock[head->datablocknum].minidata[j][cnt_1+b];   
     if(fs->datablock[head->datablocknum].minidata[j][cnt_1+b] == '\0')    
     break; 
     b++; 
     }
     inodenum = atoi(inodenum_s);   
     fd=fs->inodeblock[inodenum].f_d;   
     //inodenum을 통해 file인지 directory인지 구별  
     if((ptr[1][cnt_1] != '/')){  
     //ptr[1]에 '/'가 없을 때     
     temp[0]='\0'; 
     cnt_1=0; 
     fs->datablock[head->datablocknum].minidata[j][0] = '\0';  
     for(i = j ; i <=16 ; i++){  
     for(j = 0; j<8;j++){   
     fs->datablock[head->datablocknum].minidata[i][j]=fs->datablock[head->datablocknum].minidata[i+1][j];   
     } 
     } 
     }
     else if((fd == 'd')&&(ptr[1][cnt_1] == '/')){  
     //ptr[1]에 '/'가 있을 때     
     temp2[0]='\0';  
     while(1){   
     if(ptr[1][cnt_1+1+a] == '/'){   
     temp[a] = '\0';   
     break;}     
     temp[a] = ptr[1][(cnt_1+1)+a];    
     if(ptr[1][cnt_1+1+a] == '\0')  
     break;    
     a++; 
     }
     while(1){  
     if(ptr[1][cnt] == '\0'){   
     break;     
     }
     else if(ptr[1][cnt] == '/'){   
     break;    
     }    
     else   
     temp2[cnt] = ptr[1][cnt];  
     cnt++;
     }
     temp2[cnt] = '\0';   
     cnt_1 = strlen(temp); 
     while(1){   
     if(strcmp(head->name,temp2)==0){  
     for(i=0;i<16;i++){   
     for(j=0;j<8;j++){ 
     minidata_tmp[i][j] = fs ->datablock[head->datablocknum].minidata[i][j];
     if(minidata_tmp[i][j] == '\0')   
     break;   
     }
     }
     for(i = 0; i<16;i++){    
     minidata_tmp[i][cnt_1] = '\0';  
     }
     for(j=0;j<16;j++){  
     if(strcmp(temp,minidata_tmp[j]) == 0){  
     num = j;  
     break;
     }
     }
     b=0;
     while(1){    
     inodenum_s[b] = fs->datablock[head->datablocknum].minidata[j][cnt_1+b];    
     if(fs->datablock[head->datablocknum].minidata[j][cnt_1+b] == '\0')   
     break;   
     b++;  
     }
     inodenum = atoi(inodenum_s);    
     fd=fs->inodeblock[inodenum].f_d;   
     fs->datablock[head->datablocknum].minidata[j][0] = '\0';    
     for(i = j ; i <=16 ; i++){  
     for(j = 0; j<8;j++){   
     fs->datablock[head->datablocknum].minidata[i][j]=fs->datablock[head->datablocknum].minidata[i+1][j]; 
     }   
     }
     break;   
     }
     else{ 
     if(head->next == NULL)     
     break;    
     else  
     head=head->next;  
     }
     }
     }
     else
     printf("파일이 아닙니다. 지울 수 없습니다.\n");   
     cnt_1 = 0; 
     b=0;
     temp[0]='\0'; 
}
