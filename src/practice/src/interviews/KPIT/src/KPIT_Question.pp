/* In this exercise we want to design a solution for Mobile Billing . 
 * Our version of the Mobile Billing contains collection of customer details.
 *
 * Every customer has an id, name, number, balance, callDuration etc.
 * Assume suitable types for each data member
 * 	- id: <some unique id>
 * 	- name: "Test user"
 * 	- phoneNumber: "9800012345"
 *  - balance : 500 
 *  - totalCallDuration : 268
 *
 * Customers are classified as Prepaid,Postpaid users with some common operations,
 * e.g. credit, getBalance will be common for both. 
 * Customer id must be unique within Prepaid, Postpaid category but need not be 
 * unique across both the categories. Phone numbers must be unique across both the categories.
 * For Prepaid customers recharge is considered as credit operation
 * For postpaid customers billPay is considered as credit operation.
 * For both categories, outstanding amount is considered as balance.
 *
 * Our solution should enable us to provide the following functionality
 * E.g.:
 *      display(<id>)
 *      searchByName("Test User")
 *      searchByNumber({"9880012345"})
 *      averagePrepaidBalance()             //among all Prepaid customers
 *      queryPostpaidCustomers(<criteria>), //any criteria, say, beyond some outstanding limit
 *
 * Your code should demonstrate polymorphic behaviour,i.e. dynamic binding of calls
 * search methods should return actual instance(s),find all occurences for non-unique attributes
 * For the sake of simplicity we don't want to do any similiarity or prefix matching when
 * searching for a phone number, Only an exact match should give results.
 * You may go for substring match in case of search by name
 * Also you need not implement operations like call logging
 * which can modify balance/outstanding at this moment
 * 
 * The skeleton code below can be used as a starting point but doesn't have to.
 * The comments "fill in" are placeholders where you definitely have to put in some code when 
 * you use this skeleton code. But this doesn't mean that you shouldn't or can't put code 
 * anywhere else.
 * Also write some simple unit tests to show how you would test the functionality of the 
 * MobileBilling.Don't use any testing framework. 
 * Simple if-statements are sufficient for this exercise.
 * 
 * Hint: Think about performance versus memory tradeoffs in your design, so you can give good 
 * reasons for your decision, also clean code with polymorphic design is important.
 */

class Customer
{
    /* attributes */
    /*fill in*/ credit (/*fill in*/);
    /*fill in*/ enquireBalance (/*fill in*/);
    /* fill in any other applicable members*/
};

class PrepaidCustomer
{
   /*fill in*/
};

class PostpaidCustomer
{
   /*fill in*/
};
 
class MobileBilling
{
public:
    void addCustomer(/*fill in*/);
    void deleteCustomer(/*fill in*/);
    /*fill in*/ searchById (/*fill in*/);
    /*fill in*/ searchByName(/*fill in*/);
    /*fill in*/ searchByNumber(/*fill in*/);
    /*fill in*/ getAveragePostPaidCallDuration (/*fill in*/);
    /*fill in*/ queryPostpaidCustomers (/*fill in*/)  
    /*fill in*/ getAveragePrePaidBalance (/*fill in*/);
    /*fill in*/ queryPrepaidCustomers (/*fill in*/)  
	
private:
    /*fill in */
    /* consider suitable container(s) for collection of customers */
};
