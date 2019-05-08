/* Registo de pulseiras
 * Autor: Victor Correia
 * Versão 1
 * Actualizado em: 01/08/2018
 */

#include <SoftwareSerial.h>

long cacifo[541];
int presente[541];
String readString;
int flag=0,RX_Flag=0;//serial port sign
int i=0;
int j=0;
static long tag=0; 
char Code[14]; 

SoftwareSerial rfid = SoftwareSerial(50,51);

void setup(){
  cacifo[0]=9960110;
  cacifo[1]=2395545;
  cacifo[2]=4856751;
  cacifo[3]=2406753;
  cacifo[4]=3425139;
  cacifo[5]=2387424;
  cacifo[6]=4825835;
  cacifo[7]=4830129;
  cacifo[8]=4830887;
  cacifo[9]=5003374;
  cacifo[10]=4825819;
  cacifo[11]=4856744;
  cacifo[12]=5000867;
  cacifo[13]=4826507;
  cacifo[14]=2395461;
  cacifo[15]=5014885;
  cacifo[16]=4857993;
  cacifo[17]=4856920;
  cacifo[18]=2382907;
  cacifo[19]=3429117;
  cacifo[20]=5020734;
  cacifo[21]=4829010;
  cacifo[22]=4831004;
  cacifo[23]=4829721;
  cacifo[24]=4857998;
  cacifo[25]=4856893;
  cacifo[26]=4833093;
  cacifo[27]=4994589;
  cacifo[28]=4830877;
  cacifo[29]=4856870;
  cacifo[30]=4856811;
  cacifo[31]=4855959;
  cacifo[32]=5002219;
  cacifo[33]=4825774;
  cacifo[34]=4829657;
  cacifo[35]=4823999;
  cacifo[36]=5043030;
  cacifo[37]=4830927;
  cacifo[38]=4830903;
  cacifo[39]=4826960;
  cacifo[40]=4828780;
  cacifo[41]=5020109;
  cacifo[42]=4826559;
  cacifo[43]=4830986;
  cacifo[44]=5022568;
  cacifo[45]=4856826;
  cacifo[46]=4857021;
  cacifo[47]=4832949;
  cacifo[48]=5008383;
  cacifo[49]=4829660;
  cacifo[50]=4833060;
  cacifo[51]=2394323;
  cacifo[52]=2393275;
  cacifo[53]=3375865;
  cacifo[54]=2393350;
  cacifo[55]=2391707;
  cacifo[56]=2384756;
  cacifo[57]=2386890;
  cacifo[58]=4823580;
  cacifo[59]=2399545;
  cacifo[60]=4830133;
  cacifo[61]=2407142;
  cacifo[62]=3435095;
  cacifo[63]=2382933;
  cacifo[64]=4856840;
  cacifo[65]=4855995;
  cacifo[66]=2368809;
  cacifo[67]=5027519;
  cacifo[68]=2377826;
  cacifo[69]=4990115;
  cacifo[70]=4833835;
  cacifo[71]=4982642;
  cacifo[72]=4828929;
  cacifo[73]=4984327;
  cacifo[74]=5642275;
  cacifo[75]=5037788;
  cacifo[76]=2387633;
  cacifo[77]=2406718;
  cacifo[78]=4986573;
  cacifo[79]=4825828;
  cacifo[80]=4856999;
  cacifo[81]=2405911;
  cacifo[82]=2405764;
  cacifo[83]=4828946;
  cacifo[84]=2387775;
  cacifo[85]=5028155;
  cacifo[86]=4857905;
  cacifo[87]=2404796;
  cacifo[88]=4856907;
  cacifo[89]=2390777;
  cacifo[90]=2389273;
  cacifo[91]=4830179;
  cacifo[92]=4830137;
  cacifo[93]=4826542;
  cacifo[94]=2386899;
  cacifo[95]=2406229;
  cacifo[96]=2412313;
  cacifo[97]=4833826;
  cacifo[98]=2368453;
  cacifo[99]=2377749;
  cacifo[100]=5031809;
  cacifo[101]=4825888;
  cacifo[102]=4825839;
  cacifo[103]=4823994;
  cacifo[104]=5043015;
  cacifo[105]=4825752;
  cacifo[106]=4857043;
  cacifo[107]=4825746;
  cacifo[108]=2404984;
  cacifo[109]=4995109;
  cacifo[110]=2399284;
  cacifo[111]=4857987;
  cacifo[112]=5014096;
  cacifo[113]=4823563;
  cacifo[114]=4828468;  
  cacifo[115]=4857053;
  cacifo[116]=4824011;
  cacifo[117]=3428982;
  cacifo[118]=4836172;
  cacifo[119]=2400252;
  cacifo[120]=4855967;
  cacifo[121]=4858055;
  cacifo[122]=4826982;
  cacifo[123]=2389651;
  cacifo[124]=5000888;
  cacifo[125]=4826994;
  cacifo[126]=4854095;
  cacifo[127]=4824004;
  cacifo[128]=2400169;
  cacifo[129]=5031738;  
  cacifo[130]=5025686;
  cacifo[131]=5015416;
  cacifo[132]=4857951;
  cacifo[133]=5026304;
  cacifo[134]=4836166;
  cacifo[135]=4833023;
  cacifo[136]=4857974;  
  cacifo[137]=5023777;
  cacifo[138]=2409454;
  cacifo[139]=4823996;
  cacifo[140]=4836080;
  cacifo[141]=4856854;
  cacifo[142]=4854127;
  cacifo[143]=4833893;
  cacifo[144]=4832986;
  cacifo[145]=4833800;
  cacifo[146]=5009716;
  cacifo[147]=5021296;
  cacifo[148]=2392682;
  cacifo[149]=4855971;
  cacifo[150]=4825803;
  cacifo[151]=4856843;
  cacifo[152]=4856940;
  cacifo[153]=4829641;
  cacifo[154]=4829739;
  cacifo[155]=5016092;
  cacifo[156]=5002750;
  cacifo[157]=2405700;
  cacifo[158]=4857017;
  cacifo[159]=4829794;
  cacifo[160]=4836088;
  cacifo[161]=4835250;
  cacifo[162]=4832982;
  cacifo[163]=5037789;
  cacifo[164]=3437907;
  cacifo[165]=4828844;
  cacifo[166]=4816755;
  cacifo[167]=5000980;
  cacifo[168]=4857054;
  cacifo[169]=4855818;
  cacifo[170]=4829628;
  cacifo[171]=4835213;
  cacifo[172]=4855768;
  cacifo[173]=4826551;
  cacifo[174]=3435091;
  cacifo[175]=3368817;
  cacifo[176]=4855751;
  cacifo[177]=4828786;
  cacifo[178]=4832993;
  cacifo[179]=4829761;
  cacifo[180]=4856825;
  cacifo[181]=4834719;
  cacifo[182]=4854110;
  cacifo[183]=4855820;
  cacifo[184]=2408933;
  cacifo[185]=4830132;
  cacifo[186]=4854027;
  cacifo[187]=4856972;
  cacifo[188]=4857969;
  cacifo[189]=4824006;
  cacifo[190]=4833045;
  cacifo[191]=4830948;
  cacifo[192]=4856937;
  cacifo[193]=4854103;
  cacifo[194]=4829747;
  cacifo[195]=4855881;
  cacifo[196]=4816713;
  cacifo[197]=4856930;
  cacifo[198]=4828871;
  cacifo[199]=3429015;
  cacifo[200]=3435070;
  cacifo[201]=4830176;
  cacifo[202]=4823540;
  cacifo[203]=4857033;
  cacifo[204]=4829774;
  cacifo[205]=4830910;
  cacifo[206]=4834735;
  cacifo[207]=4831000;
  cacifo[208]=2408007;
  cacifo[209]=4829713;
  cacifo[210]=4833884;
  cacifo[211]=4829818;
  cacifo[212]=4825854;
  cacifo[213]=2394207;
  cacifo[214]=4855933;
  cacifo[215]=2383973;
  cacifo[216]=2391179;
  cacifo[217]=4836083;
  cacifo[218]=4855907;
  cacifo[219]=4826510;
  cacifo[220]=4836203;
  cacifo[221]=4833778;
  cacifo[222]=4832966;
  cacifo[223]=4833748;
  cacifo[224]=4857945;
  cacifo[225]=2377322;
  cacifo[226]=4856992;
  cacifo[227]=4856000;
  cacifo[228]=4857022;
  cacifo[229]=2396435;
  cacifo[230]=4833793;
  cacifo[231]=4856953;
  cacifo[232]=4985988;
  cacifo[233]=2393105;
  cacifo[234]=4826562;
  cacifo[235]=4816733;
  cacifo[236]=5004092;
  cacifo[237]=4856058;
  cacifo[238]=5015520;
  cacifo[239]=2393170;
  cacifo[240]=4855838;
  cacifo[241]=4829637;
  cacifo[242]=4997029;
  cacifo[243]=3429030;
  cacifo[244]=5040793;
  cacifo[245]=5042201;
  cacifo[246]=4825859;
  cacifo[247]=3385750;
  cacifo[248]=4829784;
  cacifo[249]=4829730;
  cacifo[250]=11602068;
  cacifo[251]=4830141;
  cacifo[252]=2396354;
  cacifo[253]=4858002;
  cacifo[254]=4985496;
  cacifo[255]=4836127;
  cacifo[256]=3429024;
  cacifo[257]=5002124;
  cacifo[258]=2405004;
  cacifo[259]=5028763;
  cacifo[260]=4828907;
  cacifo[261]=4982592;
  cacifo[262]=4836108;
  cacifo[263]=4829666;
  cacifo[264]=4825812;
  cacifo[265]=2405691;
  cacifo[266]=4833888;
  cacifo[267]=4825796;
  cacifo[268]=4991986;
  cacifo[269]=4830165;
  cacifo[270]=4829709;
  cacifo[271]=4826512;
  cacifo[272]=4830942;
  cacifo[273]=4833075;
  cacifo[274]=4830151;
  cacifo[275]=3435144;
  cacifo[276]=4830858;
  cacifo[277]=4828885;
  cacifo[278]=4816757;
  cacifo[279]=5013565;
  cacifo[280]=2389528;
  cacifo[281]=4833056;
  cacifo[282]=4833840;
  cacifo[283]=4858010;
  cacifo[284]=4854032;
  cacifo[285]=4856065;
  cacifo[286]=3429007;
  cacifo[287]=4858017;
  cacifo[288]=4857020;
  cacifo[289]=4857954;
  cacifo[290]=2402237;
  cacifo[291]=4829814;
  cacifo[292]=4824030;
  cacifo[293]=4823990;
  cacifo[294]=4830128;
  cacifo[295]=2384048;
  cacifo[296]=3428983;
  cacifo[297]=4855880;
  cacifo[298]=4816750;
  cacifo[299]=2390969;
  cacifo[300]=4858056;
  cacifo[301]=4836178;
  cacifo[302]=4834698;
  cacifo[303]=2412325;
  cacifo[304]=4836125;
  cacifo[305]=4858019;
  cacifo[306]=4836124;
  cacifo[307]=4858052;
  cacifo[308]=4855844;
  cacifo[309]=2386451;
  cacifo[310]=5018687;
  cacifo[311]=4853978;
  cacifo[312]=4824024;
  cacifo[313]=2393260;
  cacifo[314]=4854084;
  cacifo[315]=4853992;
  cacifo[316]=3429019;
  cacifo[317]=4828509;
  cacifo[318]=5011565;
  cacifo[319]=4816754;
  cacifo[320]=4856958;
  cacifo[321]=2411384;
  cacifo[322]=4856815;
  cacifo[323]=4826999;
  cacifo[324]=2401438;
  cacifo[325]=4826503;
  cacifo[326]=4828800;
  cacifo[327]=2392890;
  cacifo[328]=4856851;
  cacifo[329]=2409460;
  cacifo[330]=4855762;
  cacifo[331]=4830116;
  cacifo[332]=2399580;
  cacifo[333]=4825800;
  cacifo[334]=4836143;
  cacifo[335]=4828977;
  cacifo[336]=2386993;
  cacifo[337]=4830929;
  cacifo[338]=3425162;
  cacifo[339]=4828810;
  cacifo[340]=4833740;
  cacifo[341]=4828495;
  cacifo[342]=4828813;
  cacifo[343]=4856859;
  cacifo[344]=2412268;
  cacifo[345]=2405843;
  cacifo[346]=2406673;
  cacifo[347]=4836158;
  cacifo[348]=4829642;
  cacifo[349]=2386363;
  cacifo[350]=2388325;
  cacifo[351]=4823578;
  cacifo[352]=4854124;
  cacifo[353]=2399251;
  cacifo[354]=4825824;
  cacifo[355]=2402835;
  cacifo[356]=2393710;
  cacifo[357]=4825871;
  cacifo[358]=4828797;
  cacifo[359]=2407203;
  cacifo[360]=4829749;
  cacifo[361]=4828471;
  cacifo[362]=2384858;
  cacifo[363]=2376875;
  cacifo[364]=4830139;
  cacifo[365]=4856040;
  cacifo[366]=4832953;
  cacifo[367]=4858032;
  cacifo[368]=4823590;
  cacifo[369]=4854139;
  cacifo[370]=2386209;
  cacifo[371]=2386232;
  cacifo[372]=4830856;
  cacifo[373]=4856804;
  cacifo[374]=5010348;
  cacifo[375]=4836162;
  cacifo[376]=4828505;
  cacifo[377]=4825863;
  cacifo[378]=4829691;
  cacifo[379]=4829631;
  cacifo[380]=4833808;
  cacifo[381]=4857960;
  cacifo[382]=4856067;
  cacifo[383]=4856771;
  cacifo[384]=2407200;
  cacifo[385]=4833862;
  cacifo[386]=4833889;
  cacifo[387]=4856877;
  cacifo[388]=4855861;
  cacifo[389]=4836183;
  cacifo[390]=4828904;
  cacifo[391]=4830918;
  cacifo[392]=4828449;
  cacifo[393]=4833006;
  cacifo[394]=4834350;
  cacifo[395]=4825799;
  cacifo[396]=4825743;
  cacifo[397]=4828911;
  cacifo[398]=4856844;
  cacifo[399]=4854109;
  cacifo[400]=2382879;
  cacifo[401]=2395507;
  cacifo[402]=4826517;
  cacifo[403]=4828938;
  cacifo[404]=5028215;
  cacifo[405]=2407933;
  cacifo[406]=4857921;
  cacifo[407]=4816743;
  cacifo[408]=2376816;
  cacifo[409]=4854053;
  cacifo[410]=4823983;
  cacifo[411]=5021941;
  cacifo[412]=4830162;
  cacifo[413]=4855858;
  cacifo[414]=4857903;
  cacifo[415]=4828986;
  cacifo[416]=4853989;
  cacifo[417]=4854104;
  cacifo[418]=4833843;
  cacifo[419]=4856010;
  cacifo[420]=4833111;
  cacifo[421]=2409934;
  cacifo[422]=4835256;
  cacifo[423]=4855894;
  cacifo[424]=2409825;
  cacifo[425]=4830954;
  cacifo[426]=4833886;
  cacifo[427]=3429081;
  cacifo[428]=4834710;
  cacifo[429]=4833003;
  cacifo[430]=4816780;
  cacifo[431]=4828962;
  cacifo[432]=4834677;
  cacifo[433]=4855997;
  cacifo[434]=4854100;
  cacifo[435]=2384603;
  cacifo[436]=2409042;
  cacifo[437]=4823542;
  cacifo[438]=4823524;
  cacifo[439]=4857946;
  cacifo[440]=4830148;
  cacifo[441]=4857997;
  cacifo[442]=4825830;
  cacifo[443]=2384575;
  cacifo[444]=4823561;
  cacifo[445]=4830867;
  cacifo[446]=4823568;
  cacifo[447]=2388281;
  cacifo[448]=4825861;
  cacifo[449]=4830973;
  cacifo[450]=4829665;
  cacifo[451]=4855978;
  cacifo[452]=4829725;
  cacifo[453]=4832954;
  cacifo[454]=4823554;
  cacifo[455]=4830114;
  cacifo[456]=4857898;
  cacifo[457]=4830161;
  cacifo[458]=4829016;
  cacifo[459]=2393339;
  cacifo[460]=4836092;
  cacifo[461]=4829678;
  cacifo[462]=5043834;
  cacifo[463]=2408091;
  cacifo[464]=4855888;
  cacifo[465]=4828806;
  cacifo[466]=2408873;
  cacifo[467]=4834700;
  cacifo[468]=4826959;
  cacifo[469]=4833098;
  cacifo[470]=2391894;
  cacifo[471]=4823981;
  cacifo[472]=4855793;
  cacifo[473]=4858036;
  cacifo[474]=2384627;
  cacifo[475]=4856005;
  cacifo[476]=4857024;
  cacifo[477]=4829723;
  cacifo[478]=4856757;
  cacifo[479]=2411788;
  cacifo[480]=4829790;
  cacifo[481]=4857016;
  cacifo[482]=5026992;
  cacifo[483]=4857891;
  cacifo[484]=4836176;
  cacifo[485]=4836163;
  cacifo[486]=4832998;
  cacifo[487]=4828965;
  cacifo[488]=4855925;
  cacifo[489]=4858029;
  cacifo[490]=4829703;
  cacifo[491]=4834684;
  cacifo[492]=4834729;
  cacifo[493]=2394182;
  cacifo[494]=2404923;
  cacifo[495]=4824003;
  cacifo[496]=4828855;
  cacifo[497]=2384638;
  cacifo[498]=4856041;
  cacifo[499]=4855805;
  cacifo[500]=4823585;
  cacifo[501]=4828877;
  cacifo[502]=4856754;
  cacifo[503]=2396438;
  cacifo[504]=4824005;
  cacifo[505]=4824021;
  cacifo[506]=4825785;
  cacifo[507]=4855775;
  cacifo[508]=2391791;
  cacifo[509]=4829617;
  cacifo[510]=5014862;
  cacifo[511]=4857052;
  cacifo[512]=4828783;
  cacifo[513]=4836142;
  cacifo[514]=2384006;
  cacifo[515]=4832994;
  cacifo[516]=4829646;
  cacifo[517]=2394203;
  cacifo[518]=4856890;
  cacifo[519]=3437974;
  cacifo[520]=4857984;
  cacifo[521]=4855979;
  cacifo[522]=4829824;
  cacifo[523]=4826497;
  cacifo[524]=4828820;
  cacifo[525]=4836131;
  cacifo[526]=4836210;
  cacifo[527]=2410834;
  cacifo[528]=4816758;
  cacifo[529]=4835200;
  cacifo[530]=2411322;
  cacifo[531]=4830183;
  cacifo[532]=4823573;
  cacifo[533]=4829020;
  cacifo[534]=4829815;
  cacifo[535]=4828837;
  cacifo[536]=2392762;
  cacifo[537]=4828889;
  cacifo[538]=2390967;
  cacifo[539]=4857057;
  cacifo[540]=2396485;

 
  pinMode(13,OUTPUT);
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH); 
  Serial.begin(9600);
  rfid.begin(9600);
  Serial.println("This is a test for access control system");
   for(i=0;i<542;i++){
      presente[i]=0;
      //Serial.println(presente[i]);
  }     
}

long Read_ID(){   
    char temp;
    long Num=0;
    while(rfid.available() > 0){
    for(i=0;(rfid.available()>0);i++){
        temp=rfid.read();      
        delay(2);     
        if(temp==0X02){ //recieve the start bit        
            flag=1;
            i=0;
            RX_Flag=0;
        }
        if(flag==1){ //detect the start bit and recieve daad      
            if(temp==0X03){ //detect the end code,        
                flag=0;  //zero clearing
                if(i==13) 
                    RX_Flag=1;
                else 
                RX_Flag=0;
                break;
            }
            Code[i]=temp;         
        }       
    }
}         
    flag=0;

    if(RX_Flag==1){
        for(i=5;i<11;i++){
            Num<<=4;
            if(Code[i]>64)
                Num+=((Code[i])-55);
            else 
                Num+=((Code[i])-48);        
        }    
        //Serial.println(Num);
        
    }
    //delay(6000);
    return Num;
    
}


void loop(){
    static long aux;     
    if(digitalRead(10)==1){ 
        
            aux = tag;                 
            tag = Read_ID();           
            if(aux == tag || tag== 0)
                return;         
            if(aux != tag && tag!= 0){                    
                Serial.println(tag);
                i=1;      
                while(i<=540){                                         
                    if(cacifo[i]== tag){
                       if(presente[i]== 1){
                          Serial.println();
                          Serial.print("!!A PULSEIRA Nº ");
                          Serial.print(i);
                          Serial.print(" JÁ FOI LIDA!!");
                          Serial.println();
                          break;                                                     
                        }            
                        presente[i]= 1; 
                        Serial.print("Pulseira nº");
                        Serial.print(i);
                        Serial.println(" encontrada");
                        Serial.println();                        
                        break;
                    }
                
                    i++;       
                }            
                if(presente[i]== 0){
                    Serial.println();
                    Serial.println("!!PULSEIRA NÃO REGISTADA!!");
                    Serial.println();                    
                }
                
            } 
                   
        }
    
    while(Serial.available() > 0){
       
        int contador=0;
        byte lista = Serial.read();
        //Serial.println(lista);
        if(lista == 49){
            Serial.println("----Lista de faltas----");            
            Serial.println("  Pulseiras:");
            for(i=1;i<=540;i++){ 
                if(presente[i]==0){
                    Serial.print("  ");
                    Serial.println(i);
                    contador++;                    
                }    
            }            
            Serial.println("-----------------------");
            Serial.println("Em falta:");
            Serial.println();
            Serial.print("    ");
            Serial.print(contador);
            Serial.println(" pulseiras");
            Serial.println("-----------------------");
             
        }
    }
    delay(1000);          
 }
    

