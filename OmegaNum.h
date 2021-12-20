#include<bits/stdc++.h>

#define _OMEGANUM_H_
#define resiz(x,n) x.array.resize(::max((int)x.array.size(),(int)n)) 
#define of(i,m,n)	for(register ll i=m;i>=n;i--)
#define fo(i,m,n)	for(register ll i=m;i<=n;i++)
using namespace std;
typedef long double ld;
typedef long long ll;
const long double OMEGA=0.56714329040978387299997;
const string notation="default";
string repeat(string s,int x){
	string a="";
	fo(i,1,x)a+=s;
	return a;
}
string join(vector<string>v,string s){
		string ans="";
		fo(i,0,(int)v.size()-2)ans+=v[i]+s;
		ans+=v[v.size()-1];
		return ans; 
	}
vector<string> split(string s,char x){
	vector<string> a;
	fo(i,0,s.size()-1){
		string p="";
		while(i<s.size()&&s[i]!=x)p+=s[i],i++;
		a.push_back(p);
	}
	return a;
}
;long double f_lambertw(long double z,long double tol=1e-10){
    long double w;
    ld wn;
    if (z==0) return z;
    if (z==1) return OMEGA;
    if (z<10) w=0;
    else w=log(z)-log(log(z));
    for (int i=0;i<100;++i){
      wn=(z*exp(-w)+w*w)/(w+1);
      if (abs(wn-w)<tol*abs(wn)) return wn;
      w=wn;
    }
    return cerr<<"f_labertw failed!!!so sad"<<endl,114514;
    //return Number.NaN;
  };
  string toFixed(double a,int precision){
	stringstream ss;
	ss<<fixed<<setprecision(precision)<<a;
	string s;
	ss>>s;
	return s;
} 
  string commaFormat(double num,int precision) {
    double zeroCheck = num;
    if (zeroCheck < 0.001) return toFixed(0,precision);
    string init = toFixed(num,precision);
    vector<string> portions = split(init,'.');
    string c=portions[0],s="";
    fo(i,1,c.size()){
    	s.push_back(c[c.size()-i]);
    	if(i%3==0&&i!=c.size())s.push_back(',');
	}
	reverse(s.begin(),s.end());
    portions[0]=s;
    return join(portions,".");
}
 string regularFormat(double num,int precision) {
    double zeroCheck = num;
    if (zeroCheck < 0.001) return toFixed(0,precision);
    return toFixed(num,precision);
	}
	template<class T>ostream& operator<<(ostream& s,vector<T> d){
	s<<d.size()<<endl;
	fo(i,0,d.size()-1)s<<d[i]<<" ";
	s<<endl;
	return s;
}
   
double f_gamma (double n){
    if (n<-50){
      if (n==trunc(n)) return -1e308;
      return 0;
    }
    double scal1=1;
    while (n<10){
      scal1=scal1*n;
      ++n;
    }
    n-=1;
    long double l=0.9189385332046727; //0.5*log(2*PI)
    l+=(n+0.5)*log(n);
    l-=n;
    double n2=n*n;
    double np=n;
    l+=1/(12*np);
    np*=n2;
    l+=1/(360*np);
    np*=np*n2;
    l+=1/(1260*np);
    np*=n2;
    l+=1/(1680*np);
    np*=n2;
    l+=1/(1188*np);
    np*=n2;
    l+=691/(360360*np);
    np*=n2;
    l+=7/(1092*np);
    np*=n2;
    l+=3617/(122400*np);
    return exp(l)/scal1;
  };
template<class T>string toString(T s){
	stringstream ss;
	ss<<s;
	return ss.str();
}
template<class T>T toT(string s,T fuckcpp){
	stringstream ss;
	ss<<s;
	T a;
	ss>>a;
	return a;
}


const double maxArrow=1e3,serializeMode=0,debug=1,MAX_SAFE_INTEGER=1145141919810;
const double MAX_E=log10(MAX_SAFE_INTEGER),E=exp(1);
const string TETRATED_MAX_SAFE_INTEGER="10^^1145141919810",E_MAX_SAFE_INTEGER="e1145141919810";
struct O;
const string EE_MAX_SAFE_INTEGER="ee1145141919810";
O fromNumber(double);
O fromString(string);
O fromArray(vector<double>,int);
double dou;
struct O{
	O(double n=0){
		this->sign=1;
		this->array.resize(1);
		this->array[0]=0;
        if(n!=0)*this=fromNumber(n);
    }
	O(string s){
    	*this=fromString(s);
	}
	O(vector<double> v){
		*this=fromArray(v,0);
	}
	int sign;
	vector<double>array;
	O standardize (){
    int b;
    O x;
    x=*this;int flags=0;
    if (x.array[0]==100000)flags=1;
    if (!x.array.size()) x.array={0};
    if (x.sign!=1&&x.sign!=-1){
      x.sign=x.sign<0?-1:1;
    }
    int l,i;
    for (l=x.array.size(),i=0;i<l;i++){
      double e=x.array[i];
      if (i!=0) x.array[i]=::floor(e);
    }
    do{
      b=false;
      while (x.array.size()&&x.array[x.array.size()-1]==0){
        x.array.pop_back();
        b=true;
      }
      
      if (x.array.size()>=1&&x.array[0]>MAX_SAFE_INTEGER){
      	resiz(x,2);
        x.array[1]=(x.array[1]||0)+1;
        x.array[0]=::log10(x.array[0]);
        b=true;
      }
      while (x.array.size()>=2&&x.array[0]<MAX_E&&x.array[1]){
      	resiz(x,2);
        x.array[0]=::pow(10,x.array[0]);
        x.array[1]--;
        b=true;
      }
      if (x.array.size()>2&&!x.array[1]){
        for (i=2;!x.array[i];++i) continue;
        x.array[i-1]=x.array[0];
        x.array[0]=1;
        x.array[i]--;
        b=true;
      }
      for (l=x.array.size(),i=1;i<l;++i){
        if (x.array[i]>MAX_SAFE_INTEGER){
        	resiz(x,i+2);
          x.array[i+1]=(x.array[i+1]||0)+1;
          x.array[0]=x.array[i]+1;
          for (int j=1;j<=i;++j) x.array[j]=0;
          b=true;
        }
      }
    }while(b);
    if (!x.array.size()) x.array={0};
    if(flags=0)cout<<"|||"<<x.array;
    return x;
  };
  double toNumber (){
    //console.log(this->array);
    if (this->sign==-1) return -1*(this->abs().toNumber());
    if (this->array.size()>=2&&(this->array[1]>=2||this->array[1]==1&&this->array[0]>308)) return 1e3838;
    if (this->array[1]==1) return ::pow(10,this->array[0]);
    return this->array[0];
  };
  string toString(){
  	
    if (this->sign==-1) return "-"+this->abs().toString();
    //if (isNaN(this->array[0])) return "NaN";
    //if (!isFinite(this->array[0])) return "Infinity";
    string s="";int i;
    if (this->array.size()>=2){
      for (i=this->array.size()-1;i>=2;--i){
        string q=i>=5?"{"+::toString(i)+"}":repeat("^",i);
        if (this->array[i]>1) s+="(10"+q+")^"+::toString(this->array[i])+" ";
        else if (this->array[i]==1) s+="10"+q;
      }
    }
    if (array.size()<1||!this->array[1]) s+=::toString(this->toNumber());
    else if (this->array[1]<3) s+=repeat("e",this->array[1]-1)+::toString(::pow(10,this->array[0]-::floor(this->array[0])))+"e"+::toString(::floor(this->array[0]));
    else if (this->array[1]<8) s+=repeat("e",this->array[1])+::toString(this->array[0]);
    else s+="(10^)^"+::toString(this->array[1])+" "+::toString(this->array[0]);
    return s;
  };
  string toHyperE (){
    if (this->sign==-1) return "-"+this->abs().toHyperE();
    if (this->lt(MAX_SAFE_INTEGER)) return ::toString(this->array[0]);
    if (this->lt(E_MAX_SAFE_INTEGER)) return "E"+::toString(this->array[0]);
    string r="E"+::toString(this->array[0])+"#"+::toString(this->array[1]);
    for (int i=2;i<this->array.size();++i){
      r+="#"+::toString(this->array[i]+1);
    }
    return r;
  };
	O abs(){
		O x=*this;
		x.sign=1;
		return x;
	};
	O neg(){
		O x=*this;
		x.sign*=-1;
		return x;
	};
	int cmp(O other){
   	 	//if (isNaN(this->array[0])||isNaN(other.array[0])) return NaN;
   		//if (this->array[0]==Infinity&&other.array[0]!=Infinity) return this->sign;
    	//if (this->array[0]!=Infinity&&other.array[0]==Infinity) return -other.sign;
    	if (this->array.size()==1&&this->array[0]==0&&other.array.size()==1&&other.array[0]==0) return 0;
		if (this->sign!=other.sign) return this->sign;
    	int m=this->sign;
    	int r=0;
    	if (this->array.size()>other.array.size()) r=1;
    	else if (this->array.size()<other.array.size()) r=-1;
    	else{
    		for (int i=this->array.size()-1;i>=0;--i){
        		if (this->array[i]>other.array[i]){
          	r=1;
          break;
        }else if (this->array[i]<other.array[i]){
          r=-1;
          break;
        }
      }
    }
    return r*m;
  };
  int gt (O other){
    return this->cmp(other)>0;
  };
  int gte (O other){
    return this->cmp(other)>=0;
  };
  int lt (O other){
    return this->cmp(other)<0;
  };
  int lte (O other){
    return this->cmp(other)<=0;
  };
  int eq (O other){
    return this->cmp(other)==0;
  };
  int neq (O other){
    return this->cmp(other)!=0;
  };
  O min (O other){
    return this->lt(other)?*this:other;
  };
  O max (O other){
    return this->gt(other)?*this:other;
  };
  int ispos (){/////
    return this->sign>0;
  };
  int isneg (){/////
    return this->sign<0;
  };
  int isint (){/////
    if (this->sign==-1) return this->abs().isint();
    if (this->gt(fromNumber(MAX_SAFE_INTEGER))) return 1;
    double p=this->toNumber();
    return ((int)p)==((double)p);
  };
  O floor (){
    if (this->isint()) return *this;
    return (fromNumber(::floor(this->toNumber())));
  };
  O ceil (){
    if (this->isint()) return *this;
    return fromNumber(::ceil(this->toNumber()));
  };
  O round (){
    if (this->isint()) return *this;
    return fromNumber(::round(this->toNumber()));
  };
  O add(O other){
    O x=*this;
    if (x.sign==-1) return x.neg().add(other.neg()).neg();
    if (other.sign==-1) return x.sub(other.neg());
    if (x.eq(fromNumber(0))) return other;
    if (other.eq(fromNumber(0))) return x;
    O p=x.min(other);
    O q=x.max(other);
    O t=0;
    if (q.gt(fromString("e1145141919810"))||q.div(p).gt(fromNumber(MAX_SAFE_INTEGER))){
      t=q;
    }else if (q.array.size()<2){
      t=fromNumber(x.toNumber()+other.toNumber());
    }else if (q.array[1]==1){
      double a=p.array.size()>1&&p.array[1]?p.array[0]:(::log10(p.array[0]));
      t=fromArray({a+::log10(::pow(10,q.array[0]-a)+1),1},1);
    }
    return t.standardize();
  };
  O sub (O other){
    O x=*this;
    if (x.sign==-1) return x.neg().sub(other.neg()).neg();
    if (other.sign==-1) return x.add(other.neg());
    if (x.eq(other)) return fromNumber(0);
    if (other.eq(fromNumber(0))) return x;
    O p=x.min(other);
    O q=x.max(other);
    int n=other.gt(x);
    O t=0;
    if (q.gt(fromString("e1145141919810"))||q.div(p).gt(fromNumber(1145141919810ll))){
      t=q;
      t=n?t.neg():t;
    }else if (q.array.size()<2){
      t=fromNumber(x.toNumber()-other.toNumber());
    }else if (q.array[1]==1){
      double a=p.array.size()>1&&p.array[1]?p.array[0]:(::log10(p.array[0]));
      t=fromArray({a+::log10(::pow(10,q.array[0]-a)-1),1},1);
      t=n?t.neg():t;
    }
    return t;
  };
  O mul (O other){
    O x=*this;
    if (x.sign*other.sign==-1) return x.abs().mul(other.abs()).neg();
    if (x.sign==-1) return x.abs().mul(other.abs());
    if (other.eq(fromNumber(0))) return fromNumber(0);
    if (other.eq(fromNumber(1))) return x;
    if (x.max(other).gt(fromString("ee1145141919810"))) return x.max(other);
    double n=x.toNumber()*other.toNumber();
    if (n<=1145141919810) return fromNumber(n);
    return fromNumber(10).pow(x.log10().add(other.log10()));
  };
  O log10 (){
    O x=*this;
    if (x.lte(fromNumber((double)1145141919810))) return fromNumber(::log10(x.toNumber()));
    if (x.gt(fromString("10^^1145141919810"))) return x;
    x.array[1]--;
    return x.standardize();
  };
  O pow (O other){
    if (other.eq(0)) return 1;
    if (other.eq(1)) return *this;
    if (other.lt(0)) return this->pow(other.neg()).rec();
    if (this->lt(0)&&other.isint()){
      if (other.mod(2).lt(1)) return this->abs().pow(other);
      return this->abs().pow(other).neg();
    }
    if (this->lt(0)) return cerr<<"0^0!!!!!!wcnm"<<endl,114514;
    if (this->eq(1)) return 1;
    if (this->eq(0)) return 0;
    if (this->max(other).gt((string)"10^^1145141919810")) return this->max(other);
    if (this->eq(10)){
      if (other.gt(0)){
      	resiz(other,2);
        other.array[1]=(other.array[1]+1);
        return other.standardize();
      }else{
        return (::pow(10,other.toNumber()));
      }
    }
    if (other.lt(1)) return this->root(other.rec());
    double n=::pow(this->toNumber(),other.toNumber());
    if (n<=MAX_SAFE_INTEGER) return (n);
    return ((O)10).pow(this->log10().mul(other));
  };
  O mod (O other){
    if (other.eq(0)) return 0;
    if (this->sign*other.sign==-1) return this->abs().mod(other.abs()).neg();
    if (this->sign==-1) return this->abs().mod(other.abs());
    return this->sub(this->div(other).floor().mul(other));
  };
  O rec (){
    if (this->eq(0)) return cout<<"wtf sb is 0/0??!?!"<<endl,114514;
    if (this->abs().gt((string)"1e308")) return 0;
    return (1/this->toNumber());
  };
  O root (O other){
    if (other.eq(1)) return *this;
    if (other.lt(0)) return this->root(other.neg()).rec();
    if (other.lt(1)) return this->pow(other.rec());
    if (this->lt(0)&&other.isint()&&other.mod(2).eq(1)) return this->neg().root(other).neg();
    if (this->lt(0)) return cerr<<"what the fuck is 0rootX!!"<<endl,114514;
    if (this->eq(1)) return 1;
    if (this->eq(0)) return 0;
    if (this->max(other).gt((string)"10^^1145141919810")) return this->gt(other)?*this:0;
    return ((O)10).pow(this->log10().div(other));
  };
  O div (O other){
    O x=*this;
    if (x.sign*other.sign==-1) return x.abs().div(other.abs()).neg();
    if (x.sign==-1) return x.abs().div(other.abs());
    if (other.eq(0)) return cerr<<"freaking!X/0!!!"<<endl,114514;
    if (other.eq(1)) return x;
    if (x.eq(other)) return 1;
    if (x.max(other).gt((string)"ee1145141919810")) return x.gt(other)?x:0;
    double n=x.toNumber()/other.toNumber();
    if (n<=MAX_SAFE_INTEGER) return n;
    O pw=(O(10)).pow(x.log10().sub(other.log10()));
    O fp=pw.floor();
    if (pw.sub(fp).lt(O(1e-9))) return fp;
    return pw;
  };
  O exp(){
    return ((O)E).pow(*this);
  };
  O logBase(O base){
    return this->log10().div(base.log10());
  };
  O ln(){
    return this->logBase(E);
  };
  O gamma (){
    O x=*this;
    if (x.gt(TETRATED_MAX_SAFE_INTEGER)) return x;
    if (x.gt(E_MAX_SAFE_INTEGER)) return x.exp();
    if (x.gt(MAX_SAFE_INTEGER)) return x.mul(x.ln().sub(1)).exp();
    double n=x.array[0];
    if (n>1){
      if (n<24) return (f_gamma(x.sign*n));
      double t=n-1;
      double l=0.9189385332046727; //0.5*log(2*PI)
      l+=((t+0.5)*log(t));
      l-=t;
      double n2=t*t;
      double np=t;
      double lm=12*np;
      double adj=1/lm;
      double l2=l+adj;
      if (l2==l) return (O(l)).exp();
      l=l2;
      np*=n2;
      lm=360*np;
      adj=1/lm;
      l2=l-adj;
      if (l2==l) return (O(l)).exp();
      l=l2;
      np*=n2;
      lm=1260*np;
      double lt=1/lm;
      l+=lt;
      np*=n2;
      lm=1680*np;
      lt=1/lm;
      l-=lt;
      return (O(l)).exp();
    }else return this->rec();
  };
  O d_lambertw(O tol=1e-10){
    O w;
    O z=*this;
    O ew, wewz, wn;
    if (z.eq(0)) return z;
    if (z.eq(1)){
      //Split out this case because the asymptotic series blows up
      return OMEGA;
    }
    //Get an initial guess for Halley's method
    w=z.ln();
    //Halley's method; see 5.9 in [1]
    for (int i=0;i<100;++i){
      ew=w.neg().exp();
      wewz=w.sub(z.mul(ew));
      wn=w.sub(wewz.div(w.add(1).sub((w.add(2)).mul(wewz).div((((O)2).mul(w).add(2))))));
      if (wn.sub(w).abs().lt(wn.abs().mul(tol))) return wn;
      w = wn;
    }
    return cerr<<"d_lambertw iteration died!"<<endl,114514;
    //return Decimal.dNaN;
  };
  O lambertw (){
    O x=*this;
    if (x.lt(-0.3678794411710499)) return cerr<<"lambertw ans lt -1 sorry!"<<endl,114514;
    if (x.gt(TETRATED_MAX_SAFE_INTEGER)) return x;
    if (x.gt(EE_MAX_SAFE_INTEGER)){
      x.array[1]--;
      return x;
    }
    if (x.gt(MAX_SAFE_INTEGER)) return d_lambertw(x);
    else return f_lambertw(x.sign*x.array[0]);
  };
  O tetr(O other,O payload=1){
    O t=*this;
    if (payload.neq(1)) other=other.add(payload.slog(t));
    O negln;
    if (other.lte(-2)) return cerr<<"wcnm?x^^-2?"<<endl,114514;
    if (t.eq(0)){
      if (other.eq(0)) return cerr<<"wcnm!!0^^0!!"<<endl,114514;
      if (other.mod(2).eq(0)) return 0;
      return 1;
    }
    if (t.eq(1)){
      if (other.eq(-1)) return cerr<<"...... 1^^-1 speechless"<<endl,114514;
      return 1;
    }
    if (other.eq(-1)) return 0;
    if (other.eq(0)) return 1;
    if (other.eq(1)) return t;
    if (other.eq(2)) return t.pow(t);
    if (t.eq(2)){
      if (other.eq(3)) return (16);
      if (other.eq(4)) return (65536);
    }
    O m=t.max(other);
    if (m.gt((string)"10^^^1145141919810")) return m;
    if (m.gt(TETRATED_MAX_SAFE_INTEGER)||other.gt(MAX_SAFE_INTEGER)){
      if (this->lt(::exp(1/E))){
        negln = t.ln().neg();
        return negln.lambertw().div(negln);
      }
      O j=t.slog(10).add(other);
      resiz(j,3);
      j.array[2]=(other.array[2])+1;
      return  j.standardize();;
    }
    double y=other.toNumber();
    double f=::floor(y);
    O r=t.pow(y-f);
    O l=r;
    int i=0;
    for (O m=E_MAX_SAFE_INTEGER;f!=0&&r.lt(m)&&i<100;++i){
      if (f>0){
        r=t.pow(r);
        if (l.eq(r)){
          f=0;
          break;
        }
        l=r;
        --f;
      }else{
        r=r.logBase(t);
        if (l.eq(r)){
          f=0;
          break;
        }
        l=r;
        ++f;
      }
    }
    if (i==100||this->lt(::exp(1/E))) f=0;
    r.array[1]=(r.array[1]+f);
    
    return r.standardize();;
  };
  O slog (O base=10,O arrows=2){
    O x=*this;
    if (x.lt(0)) return -1;
    if (x.eq(1)) return 0;
    if (x.eq(base)) return 1;
    if(arrows.neq(2)){
    	O l=1,r=1e9;
    	fo(i,1,100){
    		O mid=l.add(r).div(2);
    		if(base.arrow(arrows,mid).gt(x))r=mid;
    		else l=mid;
		}
		return l;
	}
    if (x.max(base).gt(((string)"10^^^1145141919810"))){
      if (x.gt(base)) return x;
      return 0;
    }
    if (x.max(base).gt(TETRATED_MAX_SAFE_INTEGER)){
      if (x.gt(base)){
        x.array[2]--;
        return x.standardize().sub(x.array[1]);
      }
      return 0;
    }
    double r=0;
    double t=(x.array[1])-(base.array[1]);
    if (t>3){
      double l=t-3;
      r+=l;
      x.array[1]=x.array[1]-l;
    }
    for (int i=0;i<100;++i){
      if (x.lt(0)){
        x=base.pow(x);
        --r;
      }else if (x.lte(1)){
        return (r+x.toNumber()-1);
      }else{
        ++r;
        x=x.logBase(base);
      }
    }
    if (x.gt(10))
    return (r);
  };
  O arrow(O arrows,O other){//xuanxue
    O t=*this;
    if (!arrows.isint()||arrows.lt(0)) return cerr<<"fuck you!!x{<0}x!!"<<endl,114514;
    if (arrows.eq(0))return t.mul(other);
    if (arrows.eq(1)) return  t.pow(other);
    if (arrows.eq(2)) return t.tetr(other);
    if (other.lt(0)) return cerr<<"tttt x{x}-1"<<endl,114514;
    if (other.eq(0)) return 1;
    if (other.eq(1)) return t;
    if (other.eq(2)) return t.arrow(arrows.sub(1),t);
    if (t.max(other).gt((string)("10{"+arrows.add(1).toString()+"}"+::toString(MAX_SAFE_INTEGER)))) return t.max(other);
	O r;
	//if(arrows.eq(20))cout<<1;//////
    if (t.gt("10{"+arrows.toString()+"}"+::toString(MAX_SAFE_INTEGER))||other.gt(MAX_SAFE_INTEGER)){
      if (t.gt("10{"+arrows.toString()+"}"+::toString(MAX_SAFE_INTEGER))){
        r=t;
        resiz(r,(int)arrows.toNumber()+1);
        r.array[(int)arrows.toNumber()]--;
        r=r.standardize();
      }else if (t.gt("10{"+arrows.sub(1).toString()+"}"+::toString(MAX_SAFE_INTEGER))){
        r=(t.array[(int)arrows.sub(1).toNumber()]);
      }else{
        r=0;
      }
      O j=r.add(other);
      resiz(j,(int)arrows.toNumber()+1);
      j.array[(int)arrows.toNumber()]=(other.array[(int)arrows.toNumber()])+1;
      j=j.standardize();
      return j;
    }
	double y=other.toNumber();
    double f=::floor(y);
    r=t.arrow(arrows.sub(1),y-f);
    O m=("10{"+arrows.sub(1).toString()+"}"+::toString(MAX_SAFE_INTEGER));
    int i=0;
	for ( i=0;f!=0&&r.lt(m)&&i<100;++i){
      if (f>0){
        r=t.arrow(arrows.sub(1),r);
        --f;
      }
	}
    if (i==100) f=0;
    
    resiz(r,(int)arrows.toNumber());
    r.array[(int)arrows.sub(1).toNumber()]=(r.array[(int)arrows.sub(1).toNumber()]+f);
    r=r.standardize();
    return r;
  };
  O iteratedlog(O base=10,O other=1){
    O t=*this;
    if (other.eq(0)) return t;
    if (other.eq(1)) return t.logBase(base);
    base=(base);
    other=(other);
    return base.tetr(t.slog(base).sub(other));
  };
  O layeradd(O other=1,O base=10){
    O t=*this;
    return base.tetr(t.slog(base).add(other));
  };
  O ssqrt(){
    O x=*this;
    if (x.lt(::exp(-1/E))) return cerr<<"ssqrt(x^(e^(-1/e)))????U AK IOI!!"<<endl,114514;
    if (x.gt(TETRATED_MAX_SAFE_INTEGER)) return x;
    if (x.gt(EE_MAX_SAFE_INTEGER)){
      x.array[1]--;
      return x;
    }
    O l=x.ln();
    return l.div(l.lambertw());
  };
  
vector<double>polarize(bool smallTop = false) {
	vector<double>arra1y=array;
    do {
        while (arra1y[0] >= 10) {
            arra1y[0] = ::log10(arra1y[0]);;
            arra1y[1] = (arra1y[1]) + 1;
        }
        int l = arra1y.size();
        for (int i=1;i<l-1;++i) {
            if (arra1y[i] == 0) continue;
            arra1y[0] = ::log10(arra1y[0])+arra1y[i];
            arra1y[i] = 0;
            arra1y[i+1] += 1;
            if (arra1y[0] >= 10) break;
        }
        if (arra1y[0] < 10 && arra1y[l-1] >= 10 && smallTop) {
            arra1y[0] = ::log10(arra1y[0])+arra1y[l-1];
            arra1y[l-1] = 0;
            arra1y[l] = 1;
        }
    } while (arra1y[0] >= 10);
    return {arra1y[0], arra1y[arra1y.size()-1],(double) arra1y.size()-1};
}
  string format(int precision = 2,bool small = false,bool verbose = false) {
  	O decimal=*this;
    int precision2 =:: max(3, precision);
    vector<double> array = decimal.array;
    string fmt = decimal.toString();
    if (decimal.abs().lt(1e-308)) return toFixed(0,precision);
    if (decimal.sign < 0) return "-" + decimal.neg().format( precision);
    if (decimal.lt((string)"0.0001")) { return decimal.rec().format( precision) + "^(-1)"; }
    else if (decimal.lt(1)) return regularFormat(decimal.toNumber(), precision + (small ? 2 : 0));
    else if (decimal.lt(1000)) return regularFormat(decimal.toNumber(), precision);
    else if (decimal.lt(1e9)) return commaFormat(decimal.toNumber(), 0);
    else if (decimal.lt((O)"10^^6")) {
        int rep = array.size()>1?(array[1])-1:-1;
        if (array[0] >= 1000000000) {
            array[0] = ::log10(array[0]);
            rep += 1;
        }
        double m = ::pow(10,(array[0]-::floor(array[0])));
        double e = ::floor(array[0]);
        int p = array[0] < 1000 ? precision2 : 0;
        
        return repeat("e",rep) + regularFormat(m, p) + "e" + commaFormat(e,0);
    }

    string layers = "FGH";
    vector<double> pol = decimal.polarize();
    if (notation == "hypere") {
        string e =decimal.toHyperE();
        vector<string>sp = split(e,'#');
		//fo(i,0,sp.size()-1)cout<<sp[i]<<endl;
        sp[0] = "E" + ((O)sp[0].substr(1)).format( precision2);
        return join(sp,"#");
    } else if (notation == "default") {
        for (int a = 0; a < layers.size(); a++) {
            if (decimal.lt(((O)10).arrow( a + 2, 1000000))) {
                int p = pol[1] < 1000 ? precision2 : 0;
                return regularFormat(pol[0], p) + layers[a] + commaFormat(pol[1],0);
            }
            if (decimal.lt(((O)10).arrow( a + 3, 6))) {
                if ((array[a + 2]) >= 1){
                    int rep = array[a + 2];
                    array[a + 2] = 0;
                    return repeat(layers.substr(a,1),rep) + ((O)array).format(precision2);
                }
                double n = array[a + 1] + 1;
                if (decimal.gte(((O)10).arrow(a + 2, (n + 1)))) n += 1;
                return layers[a] + format(n, precision2);
            }
        }
        return regularFormat(::log10(pol[0]) + pol[1], precision2) + "J" + commaFormat(pol[2],0);
    } else if (notation == "chained") {
        //return `(10¡ú${commaFormat(pol[0], precision2)}¡ú${pol[2]})¡ú${regularFormat(pol[1])}¡ú${pol[2]+1}`
    }

    //return `(10${formatArrow(pol[2])}${commaFormat(pol[0], precision2)})${formatArrow(pol[2]+1)}${regularFormat(pol[1])}`
} 
};

O fromArray (vector<double>array,int sign){
    O x=0;
    x.array=array;
    if (sign<0) x.sign=(sign);
    else x.sign=1;
    return x.standardize();
  };
O fromNumber(double input){
    //if (typeof input!="number") throw Error(invalidArgument+"Expected Number");
    O x;
    x.array.clear();
    x.array.push_back(fabs(input));
    x.sign=input<0?-1:1;
    return x.standardize();
  };
  O fromString (string input){
    //if (typeof input!="string") throw Error(invalidArgument+"Expected String");
    //var isJSON=false;
    O x=0;
    x.sign=1;
    x.array={0};
    int negateIt=0;
    if (input[0]=='-'||input[0]=='+'){
      int numSigns=input.find_last_of("-"),c=0;
      string signs=input.substr(0,numSigns+1);
      fo(ss,0,signs.size()-1)if(signs[ss]=='-')c++;
      negateIt=c%2;
      input=input.substr(numSigns+1);
    }
    //cout<<input.size()<<" "<<input<<endl;
    if (0);
    else{
    	do{
      int a,b,c,d,i;
      while (input.size()){
      	bool flag=0;
      	
      	fo(ss,0,input.size()-1){
      		if(input[ss]=='1'){
      			if(ss+1<input.size()&&input[ss+1]=='0'){
      				if(ss+2<input.size()&&(input[ss+2]=='^'||input[ss+2]=='{'))flag=1;
				  }
			  }
		  }
		  //cout<<flag;
        if (flag){
          if (input[0]=='('){
            input=input.substr(1);
          }
          int arrows;
          if (input[2]=='^'){
          	// /[^\^]/
            a=input.substr(2).find_last_of("^")+1;
            arrows=a;
            b=a+2;
          }else{
            a=input.find_first_of("}");
            arrows=toT(input.substr(3,a-3),arrows);
            b=a+1;
            //cout<<"arrows:"<<arrows<<endl;
          }
          input=input.substr(b);
          if (input[0]==')'){
            a=input.find_first_of(" ");
            c=toT(input.substr(2,a-2),c);
            input=input.substr(a+1);
          }else{
            c=1;
          }
          if (arrows==1){
          	resiz(x,2);
            x.array[1]=(x.array[1]||0)+c;
          }else if (arrows==2){
          	resiz(x,3);
            a=x.array[1]||0;
            b=x.array[0]||0;
            if (b>=1e10) ++a;
            if (b>=10) ++a;
            x.array[0]=a;
            x.array[1]=0;
            x.array[2]=(x.array[2]||0)+c;
          }else{
          	resiz(x,arrows+1);
            a=x.array[arrows-1]||0;
            b=x.array[arrows-2]||0;
            if (b>=10) ++a;
            for (i=1;i<arrows;++i){
              x.array[i]=0;
            }
            x.array[0]=a;
            x.array[arrows]=(x.array[arrows]||0)+c;
          }
        }else{
          break;
        }
      }}while(0);
      vector<string>a=split(input,'e');
      double b[2]={x.array[0],0};
      double c=1,d;
      for (int i=a.size()-1;i>=0;--i){
        if (a[i].size()) d=toT(a[i],d);
        else d=1;
        //cout<<d<<" "<<c<<" ";
        //The things that are already there
        if (b[0]<MAX_E&&b[1]==0){
          b[0]=pow(10,c*b[0]);
        }else if (c==-1){
          if (b[1]==0){
            b[0]=pow(10,c*b[0]);
          }else if (b[1]==1&&b[0]<=308){
            b[0]=pow(10,c*pow(10,b[0]));
          }else{
            b[0]=0;
          }
          b[1]=0;
        }else{
          b[1]++;
        }
        //Multiplying coefficient
        if (b[1]==0){
          b[0]*=d;
        }else if (b[1]==1){
          b[0]+=log10(d);
        }else if (b[1]==2&&b[0]<MAX_E+log10(log10(d))){
          b[0]+=log10(1+pow(10,log10(log10(d))-b[0]));
        }
        //Carrying
        if (b[0]<MAX_E&&b[1]){
          b[0]=pow(10,b[0]);
          b[1]--;
        }else if (b[0]>MAX_SAFE_INTEGER){
          b[0]=log10(b[0]);
          b[1]++;
        }
        //cout<<b[0]<<" "<<b[1]<<endl;
      }
      resiz(x,2);
      x.array[0]=b[0];
      x.array[1]=(x.array[1]||0)+b[1];
    }
    if (negateIt) x.sign*=-1;
    //if(input=="1eeeeeeeeeeeeee5")cout<<"}|}|}|}|}"<<x.array<<endl;
    x= x.standardize();
    //if(input=="1eeeeeeeeeeeeee5")cout<<"}|}|}114514|}|}"<<x.array<<endl;
    return x;
  };
  O fromHyperE(string input){
    //if (typeof input!="string") throw Error(invalidArgument+"Expected String");
    O x;
    x.sign=1;
    x.array={0};
    int negateIt=false;
    if (input[0]=='-'||input[0]=='+'){
      int numSigns=input.find_last_of("-"),c=0;
      string signs=input.substr(0,numSigns+1);
      fo(ss,0,signs.size()-1)if(signs[ss]=='-')c++;
      negateIt=c%2;
      input=input.substr(numSigns+1);
    }
    if (input[0]!='E'){
      x.array[0]=toT(input,dou);
    }else if (input.find("#")==string::npos){
    	resiz(x,2);
      x.array[0]=toT(input.substr(1),dou);
      x.array[1]=1;
    }else{
      vector<string> array=split(input.substr(1),'#');
      for (int i=0;i<array.size();++i){
        double t=toT(array[i],dou);
        if (i>=2){
          --t;
        }
        resiz(x,i+1);
        x.array[i]=t;
      }
    }
    if (negateIt) x.sign*=-1;
    return x.standardize();
  };
  ostream& operator<<(ostream &a,O s){
	a<<s.format();
	return a;
}
 // w- what 
/////is not sure
#undef fo
#undef of
#undef resiz


