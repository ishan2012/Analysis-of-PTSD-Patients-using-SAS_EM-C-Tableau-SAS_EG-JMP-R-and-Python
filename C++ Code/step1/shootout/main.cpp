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
    string name = "combined_dataset_updated.txt";
    string buf;
    ifstream fin(name.c_str());
    int stream_counter = 0;
    
    vector<int> PTSD_flag;
    vector<int> patient_sk;
    vector<int> earliest_ptsd;
    
    vector<vector<int>> ptsd;
    ptsd.resize(5);
    
    vector<vector<int>> depr;
    depr.resize(5);
    
    vector<vector<int>> suicide;
    suicide.resize(5);
    
    vector<vector<int>> anxiety;
    anxiety.resize(5);
    
    vector<vector<int>> drug;
    drug.resize(5);

    while(fin>>buf)
    {
        switch(stream_counter % 28)
        {
            case 0:
                PTSD_flag.push_back(stoi(buf));
                break;
            case 1:
                patient_sk.push_back(stoi(buf));
                break;
            case 2:
                earliest_ptsd.push_back(stoi(buf));
                break;
            case 3:
                ptsd[0].push_back(stoi(buf));
                break;
            case 4:
                ptsd[1].push_back(stoi(buf));
                break;
            case 5:
                ptsd[2].push_back(stoi(buf));
                break;
            case 6:
                ptsd[3].push_back(stoi(buf));
                break;
            case 7:
                ptsd[4].push_back(stoi(buf));
                break;
            case 8:
                depr[0].push_back(stoi(buf));
                break;
            case 9:
                depr[1].push_back(stoi(buf));
                break;
            case 10:
                depr[2].push_back(stoi(buf));
                break;
            case 11:
                depr[3].push_back(stoi(buf));
                break;
            case 12:
                depr[4].push_back(stoi(buf));
                break;
            case 13:
                suicide[0].push_back(stoi(buf));
                break;
            case 14:
                suicide[1].push_back(stoi(buf));
                break;
            case 15:
                suicide[2].push_back(stoi(buf));
                break;
            case 16:
                suicide[3].push_back(stoi(buf));
                break;
            case 17:
                suicide[4].push_back(stoi(buf));
                break;
            case 18:
                anxiety[0].push_back(stoi(buf));
                break;
            case 19:
                anxiety[1].push_back(stoi(buf));
                break;
            case 20:
                anxiety[2].push_back(stoi(buf));
                break;
            case 21:
                anxiety[3].push_back(stoi(buf));
                break;
            case 22:
                anxiety[4].push_back(stoi(buf));
                break;
            case 23:
                drug[0].push_back(stoi(buf));
                break;
            case 24:
                drug[1].push_back(stoi(buf));
                break;
            case 25:
                drug[2].push_back(stoi(buf));
                break;
            case 26:
                drug[3].push_back(stoi(buf));
                break;
            case 27:
                drug[4].push_back(stoi(buf));
                break;
        }
        stream_counter++;
    }
    

    
    
    
    string out_put_file = "output.csv";
    ofstream fout(out_put_file.c_str());
    fout<<"patient_sk"<<","<<"PTSD_age"<<","<<"latest_PTSD_encounters"<<","<<"latest_depression_encounters"<<","<<"latest_suicideation_encounters"<<","<<"latest_anxiety_encounters"<<","<<"latest_drugalchohol_encounters\n";
    
    for(int i=0;i<PTSD_flag.size();i++)
    {
        if(PTSD_flag[i]==1)
        {
            for(int j=2011;j<=2015;j++)
            {
                if(earliest_ptsd[i]<=j)
                {
                    fout<<patient_sk[i]<<","<<j-earliest_ptsd[i]<<","<<ptsd[j-2011][i]<<","<<depr[j-2011][i]<<","<<suicide[j-2011][i]<<","<<anxiety[j-2011][i]<<","<<drug[j-2011][i]<<"\n";
                }
            }
        }
    }
    
    fout.close();
    
    /*
    
    string ptsd_out = "ptsd_output.txt";
    ofstream fout_ptsd(ptsd_out.c_str());
    
    string depr_out = "depr_output.txt";
    ofstream fout_depr(depr_out.c_str());
    
    string suicide_out = "suicide_output.txt";
    ofstream fout_suicide(suicide_out.c_str());
    
    string anxiety_out = "anxiety_output.txt";
    ofstream fout_anxiety(anxiety_out.c_str());
    
    string drug_out = "drug_output.txt";
    ofstream fout_drug(drug_out.c_str());
    
    for(int i=0;i<PTSD_flag.size();i++)
    {
        if(PTSD_flag[i]==1)
        {
            for(int j=2011;j<=2015;j++)
            {
                if(earliest_ptsd[i]<=j)
                {
                    //cout<<j-earliest_ptsd[i]<<" "<<ptsd[j-2011][i]<<"\n";
                    fout_ptsd<<j-earliest_ptsd[i]<<" "<<ptsd[j-2011][i]<<"\n";
                    fout_depr<<j-earliest_ptsd[i]<<" "<<depr[j-2011][i]<<"\n";
                    fout_suicide<<j-earliest_ptsd[i]<<" "<<suicide[j-2011][i]<<"\n";
                    fout_anxiety<<j-earliest_ptsd[i]<<" "<<anxiety[j-2011][i]<<"\n";
                    fout_drug<<j-earliest_ptsd[i]<<" "<<drug[j-2011][i]<<"\n";
                }
            }
        }
    }
    
    fout_ptsd.close();
    fout_depr.close();
    fout_suicide.close();
    fout_anxiety.close();
    fout_drug.close();
     */
     
    
    return 0;
}


