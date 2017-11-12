#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string.h>
#include<cctype>
using namespace std;

string s,x;
int count(int a,int b,int m)
{
	int j=a;
	for(j;j<b;j++)
    {
    	int h=0,i;
    	if(x[j]=='(')
    	{
    		int e=j,f;
	label10:for(e;x[e]!=')';e++)
			{
				if(x[e]=='(')
					h++;
			}
			for(f=e;h!=0;f++)
			{
				if(x[f]=='(')
				{
					e=f;
					goto label10;
				}
			if(x[f]==')')
				h--;
		  	}
					j=f;
		}
		if(isalpha(x[j])&&x[j]!='H')
    		m++;
    }
    return m;
}

int main()
{
	double wi;
	int l,p;
	ifstream f;
	f.open("smile2.txt");
	if(f.good())
	cout<<" file is opened now"<<endl;
	getline(f,x);
	f.close();
	p=x.length();
	cout<<" main string is "<<x<<endl;
	cout<<"length of main string is :"<<p<<endl;
	for(int i=0;i<p;i++)
	{
		if((isalpha(x[i])||x[i]=='('||x[i]==')')&&x[i]!='H')
			s+=x[i];
	}
	cout<<" substring is "<<s<<endl;
	l=s.length();
	cout<<" length of substring is "<<l<<endl;
	int z=0;
	for(int i=0;i<l;i++)
	{
	   	if(isalpha(s[i]))
	   	{
	   		z++;
	   		cout<<" "<<z<<" ";
	   		int w,e,f,t,a=0,v,r=-1,g=0,d=0,b=0,T=0;
			for(w=i;s[w]!='('&&(s[w]!=')'&&w>=0);w--);
			{
				{
					int q=0,c=0;
		    		{
		    			int h=0,b=0;
		    			for(int e=i;e!=0;e--)
	     				{
							if(s[e]==')')
								b++;
							if(s[e]=='(')
								h++;
						}
						q=h-b;
						h=0,b=0;
						int f;
						for(f=i;f!=l&&c!=q;f++)
						{
							if(s[f]==')')
								b++;
							if(s[f]=='(')
								h++;
							c=b-h;
						}
						if(q!=0)
							d=f;
					}
				}
				if(s[w]=='(')
				{ 
					r=0,e=w;
					label1:for(e;s[e]!=')';e++)
					{
						if(s[e]=='(')
							r++;
					}
					for(f=e;r!=0;f++)
					{
						if(s[f]=='(')
						{
							e=f;
							goto label1;
						}
						if(s[f]==')')
							r--;
					}
					T=f;
	     		}
				if(s[w]==')')
				{
					g=0,t=0,T=0;
					for(e=i;s[e]!=')'&&s[e]!='(';e++);
					{
						if(s[e]==')')
						{
								g=1;
								a=e+1;
						}
						if(s[e]=='(')
						{
							if(d!=0)
							{
								a=d;
								g=1;	
							}	
						}
					}
					if(g==1)
					{
						e=i;
						label2:for(e;s[e]!='(';e--)
	     				{
	     					if(isalpha(s[e])&&g==1)
								t++;
							if(s[e]==')')
								g++;
						}
						for(f=e;g!=0;f--)
						{
							if(s[f]==')')
							{
								e=f;
								goto label2;
							}
							if(isalpha(s[f])&&g==1)
								t++;
							if(s[f]=='(')
								g--;
						}
						T=f+1;
					}
				}
			    //cout<<"value of t"<<T<<","<<"dd "<<d/*<<" bb "<<t*/<<"  ";
	        }
	   		int k=z;
	   		for(int j=i+1;j<l;j++)
	   		{
	   			if(isalpha(s[j]))
	   			{
	   				k++,v=0;
	   				//cout<<"  "<<k<<" ";
					if(s[j-1]==')')
					{
						int n=0,p=0,e=j-1,f=0,c=0;		
					label:for(e;s[e]!='(';e--)
						{
							if(s[e]==')')
								n++;
							if(isalpha(s[e])&&(n==1))
						    	p++;
					    }
					    v=n;
					    //cout<<v<<",";
						for(f=e;n!=0;f--)
						{
							if(s[f]==')')
							{
								e=f;
								goto label;
							}
							if(s[f]=='(')
								n--;
							if((isalpha(s[f]))&&(n==1))
						    	p++;
					    }
					    c=f+1;
					    if(r==0&&(T<=j)&&(v>0))
					    {
					    	if(s[w]=='(')
							{
								int m=0;
								if(T==j)
								{
									if(T==d||s[i-1]!='(')
									{
										for(int h=i;s[h]!='(';h--)
											if(isalpha(s[h]))
												m++;
										k=k+m*2;
										//cout<<"fdfgfd  "<<k<<"  ";
									}
									else
									{
										k=k+2;
									}
										
		    					}
		    					if((T<j)&&(j<d))
		    					{	
		    						if(T<d)
		    						{
										if(c>=T&&c<d)
		    								k=k;
		    							else
		    								k=k+2;
									}
									else
										k=k+2;
							
								}
								if(j==d&&T!=d)
		    					{
		    						r=0,e=d-1,b=0;
									label4:for(e;s[e]!='(';e--)
									{
										if(s[e]==')')
											r++;
										if(isalpha(s[e])&&(r==1)&&(e<i))
											b++;
									}
									for(f=e;r!=0;f--)
									{
										if(s[f]==')')
										{
											e=f;
											goto label4;
										}
										if(isalpha(s[f])&&r==1&&f<i)
											b++;
										if(s[f]=='(')
											r--;	
									}
									k=k+b*2;
									//cout<<j<<" vhitya h "<<k<<" ";
								}
							}
							//cout<<t<<",";	
							//cout<<j<<",";
						}
					if(s[w]==')'&&t>0)
				   { 
				   		int e=j-1,f,n=0;
				   		label7:for(e;s[e]!='(';e--)
						{
							if(s[e]==')')
								n++;
					    }
						for(f=e;n!=0;f--)
						{
							if(s[f]==')')
							{
								e=f;
								goto label7;
							}
							if(s[f]=='(')
								n--;
					    }
					    if(s[f]==')'&&i<=f)
					    {
					    	//cout<<" hhhhhug ";
					    	k=k;
						}
						else
						{
				    		if(j==a)
				    			k=k+2*t;
				    		if(j>a)
				    		{
				    			if(d!=T&&j<=T||((t<i<d)&&j==d))
				    				k=k+2;
				    			else
								{	
				    				int h=0;
					    			for(int d=j-2;s[d]!='(';d--)
					    				if(isalpha(s[d]))
					    					h++;
					    			//cout<<"  lukkhe  "<<" hhh "<<h<<" ";
					        		k=k+p-(h+1)+1;
					       		 }	
							}	
						}
					}
						//cout<<k<<",";
						//cout<<p<<",";
						k=k-p;
						//cout<<k<<",";
					}
					if(s[j-1]=='('&&s[j-2]==')')
	   				{
	   					int r=0,x=0;
	   					int n=0,y=0,e,f,b=0,c=0;
	   					//cout<<" tttt "<<T<<" dd "<<d<<" st "<<s[T-2];
	   					{
	   						int e=d-1,f,p=0;
				   			label8:for(e;s[e]!='(';e--)
							{
								if(s[e]==')')
									p++;
					    	}
							for(f=e;p!=0;f--)
							{
								if(s[f]==')')
								{
									e=f;
									goto label8;
								}
								if(s[f]=='(')
									p--;
					    	}
					    	b=f+1;
					    }
					    //cout<<" bhai rr "<<b<<" ";
	   		            for(r=i;r>b&&r>=0;r--)
	   					{
	   						if(s[r]==')')
	   							n++;
	   						if(s[r]=='(')
								c++; 
	   						if(isalpha(s[r])&&((c-n)==1||c==0)&&(b!=T&&T!=d))
	   							x++;
	   						if(isalpha(s[r])&&((n-c)||(c-n))==0&&(b==T||T==d))
	   							x++;
						}
	   					//cout<<" janjnk "<<" xx "<<x<<" ";
	   					if(T==0&&d==0)
	   					{
						   	int e=j-2,n=0,y=0;
	   					label5:for(e;s[e]!='(';e--)
	   						{
	   							if(s[e]==')')
	   								n++;
	   							if(isalpha(s[e])&&n==1)
	   								y++;
							}
							for(f=e;n!=0;f--)
							{
								if(s[f]==')')
								{
									e=f;
									goto label5;	
								}
								if(s[f]=='(')
									n--;
								if(isalpha(s[f])&&n==1)
									y++;
							}
	   							k=k-y;
						}
						if(s[r]=='('&&T!=0)
						{
							k=z+x+1;
						}
						//cout<<"  "<<k<<" ";
					}
	   		 		wi+=k-z;
	   		 		cout<<k-z<<" + ";
	   		    }
	   		}
	   		cout<<endl;
		}
		
    }
    int i,n=0,m=0,b=0,c=0,r,d;
    for(i=0;i<p;i++)
    	if(isdigit(x[i]))
    		n++;
    	n=n/2;
    	//cout<<"nnn"<<n<<endl;
    	for(i=1;i<=n;i++)
    	{
    		int t=0,r=0,m=0;
    		for(t=0;x[t]-48!=i&&t<p;t++)
    			if(isalpha(x[t])&&x[t]!='H')
    				r++;
    		if(x[t]-48==i)
    			m=1;
    		int j;
    		for(j=t+1;x[j]-48!=i;j++)
    		{
    			int h=0;
    			if(x[j]=='(')
    			{
    				int e=j,f;
				label9:for(e;x[e]!=')'&&e<p;e++)
						{
							if(x[e]=='(')
								h++;
					   	}
						for(f=e;h!=0;f++)
						{
							if(x[f]=='(')
							{
								e=f;
								goto label9;
							}
							if(x[f]==')')
								h--;
					    }
					j=f;
				}
				if(isalpha(x[j])&&x[j]!='H')
    				m++;
    		}
    		//cout<<" alphabet are "<<j<<"  "<<m<<" "<<r<<endl;
    		d=m/2+1;
    		//cout<<"ddd "<<d;
    		int A,T=0,a;
    		{
    			int b=1;
    			for(a=t;b!=d;)
    			{
    				if(x[a]=='(')
    				{
    					int e=a,f,h=0;
			label13:for(e;x[e]!=')'&&e<p;e++)
					{
						if(x[e]=='(')
							h++;
					}
					for(f=e;h!=0;f++)
					{
						if(x[f]=='(')
						{
							e=f;
							goto label13;
						}
						if(x[f]==')')
							h--;
					}
					a=f;
					}
					else
						a++;
					if(isalpha(x[a]))
						b++;
				}
			}
			//cout<<"    aeaeaeae "<<a;
			if(m%2==0)
				A=a+1;
			else
				A=a+1;
    		for(A;A<j;A++)
    		{
    			//cout<<""
    			int h=0,i=0,y=0,q=0;
    			//cout<<"\n t "<<t+1;
    			//cout<<"\n j "<<j;
    			//cout<<"\n A "<<A;
    			y=count(t+1,A,1);
    			q=count(A,j,0);
    			//cout<<"\n count y "<<y;
    			//cout<<"\n count q "<<q;
    			if(x[A+1]=='(')
    			{
    				int e=A+1,f;
			label11:for(e;x[e]!=')'&&e<p;e++)
					{
						if(x[e]=='(')
							h++;
						if(isalpha(x[e]))
							i++;
					}
					for(f=e;h!=0;f++)
					{
						if(x[f]=='(')
						{
							e=f;
							goto label11;
						}
						if(x[f]==')')
							h--;
						if(isalpha(x[f]))
							i++;
					}
					A=f;
				}
				//cout<<" ppp "<<p;
				if(isdigit(x[A+1]))
					for(int d=A+1;d<p;d++)
						if(isalpha(x[d]))
							i++;
				//cout<<" iiii "<<i<<" ";
				c+=(((y-q)*i)+(y-q))*r;
				//cout<<" cccc "<<c<<" ";
				T=y-q;
				//cout<<" ttttt "<<T<<endl;
    		}
    		//cout<<" sdfghjkl "<<T;
    		//c+=(r*T)+(d-1);
    		//c+=r*
    		if(m==6)
    			c+=2*r;
    		else if(m==5||m==4)
    			c+=1*r;
    		else if(m==3)
    			c+=0;
    		//cout<<endl<<m<<". "<<b<<","<<endl;
    		c+=b;
		}
		cout<<" ring effect "<<c<<endl;
		cout<<" side chain effect "<<wi<<endl;
		wi=wi-c;
    cout<<" HEY YOUR WEINER INDEX IS "<<wi<<endl;
    system("PAUSE");
    return 0;
}
