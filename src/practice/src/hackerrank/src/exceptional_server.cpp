#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
    static int compute(long long A, long long B)
    {
		load += 1;

            if(A < 0)
            {
                throw std::invalid_argument("A is negative");
            }
            vector<int> v(A, 0);
            int real = -1, cmplx = sqrt(-1);
            if(B == 0) throw 0;
            real = (A/B)*real;
            int ans = v.at(B);
            return real + A - B*ans;




	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) 
    {
		long long A, B;
		cin >> A >> B;
        
        
        try 
        {
            Server::compute(A, B);

        }
        catch (std::invalid_argument e)
        {
            cout << "Exception: " << e.what() << endl;
        }
        catch (std::bad_alloc e) 
        {
            cout << "Not enough memory" << endl;
        }
        catch (std::length_error e) 
        {
            cout << e.what() << endl;
        }
        catch (std::out_of_range e) 
        {
            cout << e.what() << endl;
        }
        catch (std::runtime_error e) 
        {
            cout << e.what() << endl;
        }

        catch (std::domain_error e) 
        {
            cout << e.what() << endl;
        }
        catch (std::logic_error e) 
        {
            cout << e.what() << endl;
        }
//         catch (std::bad_typeid e) 
//         {
//             cout << e.what() << endl;
//         }
        catch (std::bad_exception e) 
        {
            cout << e.what() << endl;
        }
//         catch (std::bad_cast e) 
//         {
//             cout << e.what() << endl;
//         }
        
        catch (std::range_error e) 
        {
            cout << e.what() << endl;
        }
        
        catch (std::underflow_error e) 
        {
            cout << e.what() << endl;
        }
        
        catch (std::overflow_error e) 
        {
            cout << e.what() << endl;
        }
        catch (std::exception e) 
        {
            cout << "Other Exception" << endl;
        }
        catch (...) 
        {
            cout << "Other Exception" << endl;
        }
    }
    cout << Server::getLoad() << endl;

	
	return 0;
}
