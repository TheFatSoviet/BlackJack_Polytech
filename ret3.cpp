using namespace std;


class ret3
{
public:

bool pioche_ret3()
{
    static int i=0;

    if (i<1)
    {
      i=i+1;
      return true;
    }
    else
    {
      i=0;
      return false;
    }

}
};
