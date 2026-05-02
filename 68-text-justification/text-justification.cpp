// class Solution {
// public:
//     int MAX_WIDTH;
//     string getFinalWord(int i, int j, int eachWordSpace, int extraSpace, vector<string>& words) {
//         string s;

//         for(int k = i; k < j; k++) {
//             s += words[k];

//             if(k == j-1)
//                 continue;

//             for(int space = 1; space <= eachWordSpace; space++)
//                 s += " ";

//             if(extraSpace > 0) {
//                 s += " ";
//                 extraSpace--;
//             }
//         }

//         while(s.length() < MAX_WIDTH) {
//             s += " ";
//         }
        
//         return s;
//     }
    
//     vector<string> fullJustify(vector<string>& words, int maxWidth) {
//         vector<string> result;
//         int n     = words.size();
//         MAX_WIDTH = maxWidth;
//         int i     = 0;
        
//         while(i < n) {
//             int lettersCount = words[i].length();
//             int j            = i+1;
//             int spaceSlots   = 0;
            
//             while(j < n && spaceSlots + lettersCount + words[j].length() + 1 <= maxWidth) {
//                 lettersCount += words[j].length();
//                 spaceSlots   += 1;
//                 j++;
//             }
            
//             int remainingSlots = maxWidth - lettersCount;
            
            
//             int eachWordSpace = spaceSlots == 0 ? 0 : remainingSlots / spaceSlots;
//             int extraSpace    = spaceSlots == 0 ? 0 : remainingSlots % spaceSlots;
            
//             if(j == n) { //Means we are on last line - Left justfied
//                 eachWordSpace = 1;
//                 extraSpace    = 0;
//             }
            
            
//             result.push_back(getFinalWord(i, j, eachWordSpace, extraSpace, words));
//             i = j;
//         }
        
//         return result;
//     }
// };
class Solution {
public:
    int maxw;
    string insert(int i,int j, int each_gaddha_space,int remaining_gadddhe,vector<string>& words){

        string s;

        for(int k=i;k<j;k++){
            s+=words[k];

             if(k == j-1)
                continue;
            for(int l=0;l<each_gaddha_space;l++){
                s+=" ";
            }
            if(remaining_gadddhe>0){
                s+=" ";
                remaining_gadddhe--;
            }
        }
         //for only word in line
             while(s.length() < maxw) {
            s += " ";
       }
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>result;
        int n=words.size();
        maxw=maxWidth;
        int i=0;
        while(i<n){
            int letters= words[i].size();
            int gaddhe=0;

            int j=i+1;
            while(j<n && words[j].length()+letters+gaddhe+1<=maxw){
                letters+=words[j].length();
                gaddhe+=1;
                j++;
            }
            int rem_slots= maxw-letters;
            int each_gaddha_space= gaddhe==0?0: rem_slots/gaddhe;
            int remaining_gadddhe=  gaddhe==0?0:rem_slots% gaddhe;

            if(j==n){
                //last line
                each_gaddha_space=1;
                remaining_gadddhe=0;
            }
            result.push_back(insert(i,j,each_gaddha_space,remaining_gadddhe,words));
            i=j;
        }
        return result;
    }
};





























