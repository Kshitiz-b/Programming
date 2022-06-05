#include<stdio.h>
int main(void){
	    int n,m,moreAdmissionsInAllCampuses=0;  /*n stores the number of campuses and m stores the number of courses and moreAdmissionsInAllCampuses stores the number of courses which have more admissions than intake*/
    scanf("%d %d",&n,&m);

    int admissions[n][m];   /*2d array stores the admissions in courses in all campuses the row represents the campuses and m represents the courses*/
    int admissionsSanctioned[n][m];   /*2d array stores the admissions sanctioned in courses in all campuses the row represents the campuses and m represents the courses*/

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&admissions[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&admissionsSanctioned[i][j]);
        }
    }
    
    printf("Entered admissions (campus-wise):\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",admissions[i][j]);
        }
        printf("\n");
    }

    printf("Admissions Campus-wise with respect to maximum intake:\n");
    for(int i=0;i<n;i++){
        int moreAdmissions=0;   /*stores the campuses which have more admissions than sanctioned*/
        for(int j=0;j<m;j++){
            if(admissions[i][j]>admissionsSanctioned[i][j]){   /*this block checks if the course of a particular campus has more admissions than sacntioned*/
                moreAdmissions++;
            }
        }
        printf("Campus %d got more admissions in Courses:%d\n",i+1,moreAdmissions);
    }

    printf("Admissions Course-wise with respect to maximum intake:\n");
    for(int j=0;j<m;j++){
        int moreAdmissions=0;  /*stores the number of courses which have more admissions in campuses than sanctioned*/
        for(int i=0;i<n;i++){
            if(admissions[i][j]>admissionsSanctioned[i][j]){
                moreAdmissions++;
            }
        }
        printf("Course %d got more admissions in %d campuses\n",j+1,moreAdmissions);

        /*this if block checks if a particular course sees more admissions in all the campuses if it does then it increases the variable concerned*/
        if(moreAdmissions==n){  /*As the course having more admissions in all campuses will have made the moreAdmissions variable go to n which is the number of campuses*/
            moreAdmissionsInAllCampuses++;
        }
    }

    /*Implemented this block by adding the admissions course wise for all campus in their particular iteration*/
    printf("The sorted order of campus-wise total admissions in all courses:\n");
    for(int i=0;i<n;i++){
        int campusAdmissions=0;
        for(int j=0;j<m;j++){
            campusAdmissions+=admissions[i][j];
        }
        printf("%d ",campusAdmissions);
    }

    if(moreAdmissionsInAllCampuses==0){
        printf("\nThere is no course which got admissions more than intake in all campuses.");
    }
    else{
        printf("\n%d course got more admissions than intake in all campuses",moreAdmissionsInAllCampuses);
    }
	
	return 0;
}