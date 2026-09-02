class Solution { 
public: 
    typedef pair<int,char>p; 

    string frequencySort(string s) { 
        int n=s.length(); 
        priority_queue<p,vector<p>>pq; 
        vector<int>freq(128); 

        for(char ch: s){ 
            freq[ch]++;             // changed
        } 

        for(int i=0;i<128;i++){     // changed
            if(freq[i]>0){          // changed
                pq.push({freq[i],char(i)});  // changed
            }
        } 

        string res=""; 

        while(!pq.empty()){ 
            int times=pq.top().first; 
            char ch=pq.top().second; 

            for(int i=0;i<times;i++){ 
                res+=ch; 
            } 
            pq.pop(); 
        } 

        return res; 
    } 
};