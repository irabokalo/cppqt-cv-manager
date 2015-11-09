#include <iostream>
#include <string>
#include <array>
#include<list>
#include <vector>
using namespace std;
// We should keep list of programmers CVs
// For each CV we have
//      * name field
//      * birthday year
//      * list of skills
//      * list of previous jobs
//      * we would like to print our CV

class JobRecord
{
    int mStartYEar;
    int mEndYear;
   string  position;
   string nameCompany;

public:
    JobRecord():mStartYEar(0), mEndYear(0), position(" "), nameCompany(" ") {}
    JobRecord(int start, int end, string pos,string com):mStartYEar(start), mEndYear(end),position(pos),
     nameCompany(com)
    {}
    bool isValid()
    {
        return((position!=" ")&&(nameCompany!=" ")&&(mStartYEar>1960)&&(mEndYear>1960));
    }
    void print()
    {
        cout<<mStartYEar<<" "<<mEndYear<<" "<<position<<" "<<nameCompany<<endl;
    }
};


class CV
{
    string Mname;
    int mBirthYear;
    vector<string>mSkills;
    vector<JobRecord>mPreviousJobs;

public:
    CV( string name, int birthYear, vector<string> skills, vector<JobRecord>mPrev) :
        Mname(name)
      , mBirthYear(birthYear)
      , mSkills(skills)
      ,mPreviousJobs(mPrev)
{
}
    void addJobRecord(const JobRecord&a)
    {
        mPreviousJobs.push_back(a);
    }
void jobRecords() const
{
    for(auto elem: mPreviousJobs)
    {
        elem.print();
    }
  }
    bool isValid() const
    {
        return !Mname.empty()
                && ((mBirthYear > 1970) && (mBirthYear < 1995))
                && !mSkills.empty()
                && !mPreviousJobs.empty();
    }
    void print()
    {
        cout<<Mname<<" "<< mBirthYear << " "<<endl;
        jobRecords();
        for(auto elem: mSkills)
        {
            cout<<elem<<" ";
        }
    }

};
void main()
{
    vector<string> Skills;
    Skills.push_back("c++");
    vector<JobRecord> array;
    JobRecord men(2003,2003,"manager","microsoft");
    array.push_back(men);
    CV lahudra("Irachka",1998,Skills,array);

    system("pause");
}

