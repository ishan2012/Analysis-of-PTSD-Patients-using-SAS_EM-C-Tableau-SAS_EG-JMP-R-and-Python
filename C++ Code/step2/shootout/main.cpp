//
//  main.cpp
//  shootout
//
//  Created by Hao Pan on 3/4/18.
//  Copyright © 2018 Hao Pan. All rights reserved.
//

#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<queue>
#include<string>
#include<time.h>
#include<algorithm>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int stoi(string i)
{
    stringstream geek(i);
    int s=0;
    geek >> s;
    return s;
}

int main()
{
    string name = "input_of_step2.txt";
    string buf;
    ifstream fin(name.c_str());
    int stream_counter = 0;
    
    
    vector<int> patient_sk;
    vector<int> ptsd_age;
    vector<int> latest_ptsd;
    vector<int> latest_depression;
    vector<int> latest_suicide;
    vector<int> latest_anxiety;
    vector<int> latest_drug;
    
    

    while(fin>>buf)
    {
        switch(stream_counter % 7)
        {
            case 0:
                patient_sk.push_back(stoi(buf));
                break;
            case 1:
                ptsd_age.push_back(stoi(buf));
                break;
            case 2:
                latest_ptsd.push_back(stoi(buf));
                break;
            case 3:
                latest_depression.push_back(stoi(buf));
                break;
            case 4:
                latest_suicide.push_back(stoi(buf));
                break;
            case 5:
                latest_anxiety.push_back(stoi(buf));
                break;
            case 6:
                latest_drug.push_back(stoi(buf));
                break;
        }
        stream_counter++;
    }
    
    
    vector<int> no_ptsd_flag;
    vector<int> no_depr_flag;
    vector<int> no_suicide_flag;
    vector<int> no_anxiety_flag;
    vector<int> no_drug_flag;
    
    no_ptsd_flag.resize((int)patient_sk.size());
    no_depr_flag.resize((int)patient_sk.size());
    no_suicide_flag.resize((int)patient_sk.size());
    no_anxiety_flag.resize((int)patient_sk.size());
    no_drug_flag.resize((int)patient_sk.size());
    
    for(int i=1;i<=152978;i++)
    {
        int flag_1=0;
        cout<<i<<endl;
        int temp_sum_ptsd=0;
        int temp_sum_depr=0;
        int temp_sum_suicide=0;
        int temp_sum_anxiety=0;
        int temp_sum_drug=0;
        for(int j=0;j<patient_sk.size();j++)
        {
            if(patient_sk[j]==i)
            {
                flag_1=1;
                temp_sum_ptsd+=latest_ptsd[j];
                temp_sum_depr+=latest_depression[j];
                temp_sum_suicide+=latest_suicide[j];
                temp_sum_anxiety+=latest_anxiety[j];
                temp_sum_drug+=latest_drug[j];
            }
        }
        
        if(flag_1==1)
        {
        //ptsd
        if(temp_sum_ptsd==0)
        {
            for(int m=0;m<patient_sk.size();m++)
            {
                if(patient_sk[m]==i)
                {
                    no_ptsd_flag[m]=1;
                }
            }
        }
        else
        {
            for(int m=0;m<patient_sk.size();m++)
            {
                if(patient_sk[m]==i)
                {
                    no_ptsd_flag[m]=0;
                }
            }
        }
        
        //depr
        if(temp_sum_depr==0)
        {
            for(int m=0;m<patient_sk.size();m++)
            {
                if(patient_sk[m]==i)
                {
                    no_depr_flag[m]=1;
                }
            }
        }
        else
        {
            for(int m=0;m<patient_sk.size();m++)
            {
                if(patient_sk[m]==i)
                {
                    no_depr_flag[m]=0;
                }
            }
        }
        
        //suicide
        if(temp_sum_suicide==0)
        {
            for(int m=0;m<patient_sk.size();m++)
            {
                if(patient_sk[m]==i)
                {
                    no_suicide_flag[m]=1;
                }
            }
        }
        else
        {
            for(int m=0;m<patient_sk.size();m++)
            {
                if(patient_sk[m]==i)
                {
                    no_suicide_flag[m]=0;
                }
            }
        }
        
        //anxiety
        if(temp_sum_anxiety==0)
        {
            for(int m=0;m<patient_sk.size();m++)
            {
                if(patient_sk[m]==i)
                {
                    no_anxiety_flag[m]=1;
                }
            }
        }
        else
        {
            for(int m=0;m<patient_sk.size();m++)
            {
                if(patient_sk[m]==i)
                {
                    no_anxiety_flag[m]=0;
                }
            }
        }

        //drug
        if(temp_sum_drug==0)
        {
            for(int m=0;m<patient_sk.size();m++)
            {
                if(patient_sk[m]==i)
                {
                    no_drug_flag[m]=1;
                }
            }
        }
        else
        {
            for(int m=0;m<patient_sk.size();m++)
            {
                if(patient_sk[m]==i)
                {
                    no_drug_flag[m]=0;
                }
            }
        }
        }
        else
        {
            continue;
        }
    }
    
    string out_put_file = "output_step_2.csv";
    ofstream fout(out_put_file.c_str());
    
    
    fout<<"patient_sk"<<","<<"PTSD_age"<<","<<"latest_PTSD_encounters"<<","<<"latest_depression_encounters"<<","<<"latest_suicideation_encounters"<<","<<"latest_anxiety_encounters"<<","<<"latest_drugalchohol_encounters"<<","<<"no_ptsd_flag"<<","<<"no_depression_flag"<<","<<"no_suicide_flag"<<","<<"no_anxiety_flag"<<","<<"no_drug_flag\n";
    
    for(int i=0;i<patient_sk.size();i++)
    {
        fout<<patient_sk[i]<<","<<ptsd_age[i]<<","<<latest_ptsd[i]<<","<<latest_depression[i]<<","<<latest_suicide[i]<<","<<latest_anxiety[i]<<","<<latest_drug[i]<<","<<no_ptsd_flag[i]<<","<<no_depr_flag[i]<<","<<no_suicide_flag[i]<<","<<no_anxiety_flag[i]<<","<<no_drug_flag[i]<<"\n";
    }
    
    fout.close();
    return 0;
}


