#include "DSA.h"

#define MAX 500
// minimum number of jump to the end
int DSA::jump_To_end(int arr[], int n)
{
	if (n == 1)
	{
		return 0;
	}
	int res = INT_MAX;

	for (int i = n - 2; i >= 0; i--)
	{
		if (i + arr[i] >= n - 1)
		{
			int sub = jump_To_end(arr, i + 1);
			if (sub != INT_MAX)
			{
				res = std::min(res, sub + 1);
			}
		}
	}
	return res;
}
int DSA::findDuplicate3(std::vector<int>& nums)
{
	if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1;
}

//Longest consecutive subsequence
int DSA::Long_subsequnce(int arr[], int n)
{
	int	Init_no = 0;
	int Count = 0;

	std::sort(arr, arr + n);

	std::vector<int>vec;
	vec.push_back(arr[0]);

	for (int i = 1; i < n; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			vec.push_back(arr[i]);
		}
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i < 0 && vec[i] == vec[i - 1] + 1)
		{
			Count++;
		}
		else
		{
			Count = 1;
		}
		Init_no = std::max(Init_no, Count);
	}
	return Init_no;
}

int DSA::Dupli_no_arr(std::vector<int>& nums)
{
	int temp = {};
	std::sort(nums.begin(), nums.end());
	for (size_t i = 0; i < nums.size(); i++)
	{
		temp = nums[i];
		if (nums[i + 1] == temp)
		{
			std::cout << temp;
		}
	}
	return temp;
}

int DSA::Max_profit(std::vector<int>& prices)
{
	int Max_profit = 0;
	int Min_price = INT_MAX;

	for (size_t i = 0; i < prices.size(); i++)
	{
		Min_price = std::min(Min_price, prices[i]);
		Max_profit = (std::max(Max_profit, prices[i] - Min_price));
	}
	return Max_profit;
}

int DSA::Multiply_fact_largest(int x, int res[], int Size)
{
	int carry = 0;
	for (int i = 0; i < Size; i++)
	{
		int prod = res[i] * x + carry;
		res[i] = prod % 10;
		carry = prod / 10;
	}
	while (carry)
	{
		res[Size] = carry % 10;
		carry = carry / 10;
		Size++;
	}
	return Size;
}

void DSA::Fact_largest(int n)
{
	int res[MAX];
	res[0] = 1;
	int R_size = 1;
	for (int x = 2; x <= n; x++)
	{
		R_size = Multiply_fact_largest(x, res, R_size);
	}
	std::cout << '\n';
	std::cout << "Factorial of given number is \n";
	for (int i = R_size - 1; i >= 0; i--)
		std::cout << res[i];
}

//Count pairs with given sum
int DSA::countpair_sum(int arr[], int n, int sum)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] == sum)
				count++;
		}
	}
	return count;
}

std::vector<int> DSA::RunningSum(std::vector<int>& nums)
{
	for (size_t i = 1; i < nums.size(); i++)
	{
		nums[i] += nums[i - 1];
	}
	return nums;
}

std::string DSA::defangIPaddr(std::string& address)
{
	for (int i = address.size() - 2; i >= 0; i--)
	{
		if (address[i + 1] == '.')
			address = address.substr(0, i + 1) + "[.]" + address.substr(i + 2);
	}
	return address;
}

std::vector<bool> DSA::kidsWithCandies(std::vector<int>& candies, int extraCandies)
{
	std::vector<bool> out;
	int Max = *max_element(candies.begin(), candies.end());
	for (size_t i = 0; i < candies.size(); i++)
	{
		(candies[i] + extraCandies >= Max) ? out.push_back(true) : out.push_back(false);
	}
	return out;
}

int DSA::maximumWealth(std::vector<std::vector<int>>& accounts)
{
	int Richest = 0;
	for (std::vector<int>& customers : accounts)
	{
		Richest = std::max(Richest, std::accumulate(customers.begin(), customers.end(), 0));
	}
	return Richest;
}

std::vector<int> DSA::shuffle(std::vector<int>& nums, int n)
{
	std::vector<int> v;
	int j = n;
	for (int i = 0; i < n; i++)
	{
		v.push_back(nums[i]);
		v.push_back(nums[j]);
		j++;
	}
	return v;
}

int DSA::numIdenticalPairs(std::vector<int>& nums)
{
	int count = 0;
	std::unordered_map<int, int>u_mp;
	for (auto& i : nums)
	{
		count += u_mp[i]++;
	}
	std::cout << count;
	return count;
}

std::vector<int> DSA::decompressRLElist(std::vector<int>& nums)
{
	std::vector<int> ans;
	for (size_t i = 0; i < nums.size(); i += 2)
	{
		ans.insert(ans.end(), nums[i], nums[i += 1]);
	}
	return ans;
}

std::string DSA::interpret(std::string command)
{
	std::string ans;
	size_t i = 0;
	while (i < command.size())
	{
		if (command[i] == 'G')
		{
			ans += 'G';
			++i;
		}
		else if (command[i + 1] == ')')
		{
			ans += 'o';
			i += 2;
		}
		else
		{
			ans += "al";
			i += 4;
		}
	}
	return ans;
}

int DSA::maxProfit(int price[], int n)
{
	int* profit = new int[n];
	for (int i = 0; i < n; i++)
	{
		profit[i] = 0;
	}
	int maxPrice = price[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (price[i] > maxPrice)
		{
			maxPrice = profit[i];
		}
		profit[i] = std::max(profit[i + 1], maxPrice - price[i]);
	}
	int minPrice = price[0];
	for (int i = 1; i < n; i++)
	{
		if (price[i] < minPrice)
		{
			minPrice = price[i];
		}
		profit[i] = std::max(profit[i - 1], profit[i] + (price[i] - minPrice));
	}
	int result = profit[n - 1];
	delete[]profit;
	return result;
}

//reverse of array
void DSA::R_arr(int arr[], int n)
{
	int start = 0, end = n - 1;
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

//reverse of integer
int DSA::R_Integers(int x)
{

	int r = 0;
	int sum = 0;
	bool minus = false;
	if (x < 0)
		minus = true;
	while (abs(x) > 0)
	{
		r = abs(x) % 10;
		sum = sum * 10 + r;
		x /= 10;
	}
	if (minus)
		sum *= -1;
	if (sum > INT_MAX || sum < INT_MIN)
		return 0;
	return sum;
}

// max min heap of array
void DSA::Min_max_arr()
{
	int i, j, min_idx;
	int arr[] = { 6,5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
			std::swap(arr[min_idx], arr[i]);
		}
	}
	std::cout << "Smallest Element :" << arr[0] << "\nLargest Element:" << arr[n - 1];
}

//Kadanes algo
int DSA::maxSubArray(std::vector<int>& nums)
{
	int sum = 0;
	int Max = INT_MIN;
	for (auto Itr : nums)
	{
		sum += Itr;
		Max = std::max(sum, Max);
		if (sum < 0)
			sum = 0;
	}
	return Max;
}

//cyclic rotate the array by one
void DSA::cycle_by_one(int arr[], int n)
{
	{
		for (int i = 0; i <= n - 1; i++)
		{
			std::swap(arr[i], arr[n - 1]);
		}
	}
}

//move all negative at the starting of the list
void DSA::Rearrange_negatives(int arr[], int n)
{
	{
		int j = 0;
		for (int i = 0; i <= n - 1; i++)
		{
			if (arr[i] < 0)
			{
				if (i != j)
					std::swap(arr[i], arr[j]);
				else
					j++;
			}
		}
	}
}

//Minimize the maximum difference between the heights
int DSA::getMinDiff(int arr[], int n, int k)
{
	std::sort(arr, arr + n);
	int i, mx, mn, ans;
	ans = arr[n - 1] - arr[0];  // this can be one possible solution

	for (i = 0; i < n; i++)
	{
		if (arr[i] >= k)  // since height of tower can't be -ve so taking only +ve heights
		{
			mn = std::min(arr[0] + k, arr[i] - k);
			mx = std::max(arr[n - 1] - k, arr[i - 1] + k);
			ans = std::min(ans, mx - mn);
		}
	}
	return ans;
}

//sum of two numbers
void DSA::Two_sum()
{
	int arr[] = { 3,2,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 6;
	int i, j;
	int temp_indx, temp_indx2;
	for (i = 0; i < n; i++)
	{
		temp_indx = i;
		//std::cout << arr[temp_indx] << "i ";
		for (j = i + 1; j < n; j++)
		{
			temp_indx2 = j;
			if (arr[temp_indx] + arr[temp_indx2] == k)
			{
				std::cout << "indeies:" << i << " indices:" << j << '\n';
			}
			else
			{
				break;
			}
		}
	}
}

//Two sum problem 4ms brute
std::vector<int> DSA::Two_sum_vector(std::vector<int>& nums, int target)
{
	std::vector<int> results;
	int temp_indx, temp_indx2;
	for (size_t i = 0; i < nums.size(); i++)
	{
		temp_indx = i;
		//std::cout << arr[temp_indx] << "i ";
		for (size_t j = i + 1; j < nums.size(); j++)
		{
			temp_indx2 = j;
			if (i == j)
			{
				continue;
			}
			else
			{
				int sum = nums[temp_indx] + nums[temp_indx2];
				if (sum == target)
				{
					if (results.size() < 2)
					{

						results.push_back(i);
						results.push_back(j);
						std::cout << "indeies:" << i << " indices:" << j << '\n';
					}
					else
					{
						break;
					}
				}
				else
				{
					continue;
				}
			}
			return results;
		}
	}
	return results;
}

void DSA::Rev_Exution()
{
	int arr[] = { 6,5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	R_arr(arr, n);

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i];
	}
	std::cout << '\n';
}

void DSA::Pub_Excute_fun()
{
	DSA daa;
	daa.Two_sum();
	int arr[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 6, 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = sizeof(arr2) / sizeof(arr2[0]);
	std::cout << "MiniumumJumps:" << daa.jump_To_end(arr, n);
	Fact_largest(100);
}

//Douuble Linked list
DNode* DNode::DGetNewNode(int x)
{
	DNode* m_Node = new DNode();

	m_Node->data = x;
	m_Node->Prev = nullptr;
	m_Node->Next = nullptr;
	return m_Node;
}
void DNode::InsertAt(DNode** Head, int x)
{
	DNode* new_Node = DGetNewNode(x);
	new_Node->Next = *Head;
	new_Node->Prev = nullptr;
	if (*Head != nullptr)
	{
		(*Head)->Prev = new_Node;
	}
	*Head = new_Node;
}

void DNode::PrintList(DNode* Head)
{

	DNode* temp = Head;
	std::cout << "Data List:";
	while (temp != nullptr)
	{
		std::cout << " " << temp->data;
		temp = temp->Next;
	}
}
void DNode::ReversePrint(DNode* Head)
{
	DNode* Last = Head;
	if (Head == NULL)
		return;

	while (Head != NULL)
	{
		std::cout << " " << Head->data;
		Last = Head;
		Head = Head->Next;
	}

	std::cout << "\nReverse:";

	std::cout << "\nTraversal in reverse direction \n";
	while (Last != NULL)
	{
		std::cout << " " << Last->data << " ";
		Last = Last->Prev;
	}

	std::cout << std::endl;
}
int DNode::ListCount(DNode* Head)
{
	int count = 0;
	while (Head != nullptr)
	{
		count++;
		Head = Head->Next;
	}
	std::cout << "Number of Elements in the list are: "
		<< count;
	return count;
};
void DNode::DLinkRun()
{
	DNode* Head = nullptr;

	Head->InsertAt(&Head, 2);
	Head->InsertAt(&Head, 4);
	Head->InsertAt(&Head, 6);
	// Head->PrintList(Head);
	Head->ReversePrint(Head);
	Head->ListCount(Head);
	delete Head;
}

std::shared_ptr<BST> BST::BSTGetNewNode(int data)
{
	std::shared_ptr<BST> newNode = std::make_shared<BST>(data);
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	return newNode;
}

void BST::Insert_BST(std::shared_ptr<BST>& root, int data)
{
	if (root == nullptr)
	{
		root = BSTGetNewNode(data);
		return;
	}
	(data > root->data) ? Insert_BST(root->Left, data) : Insert_BST(root->Right, data);
}
void BST::Insert(int data)
{
	Insert_BST(Root, data);
}

bool BST::search_BST(std::shared_ptr<BST>& root, int data)
{
	if (root == nullptr)
		return false;

	else if (root->data == data)
	{
		return true;
	}
	else if (root->data <= data)
	{
		return search_BST(root->Left, data);
	}
	else
	{
		return search_BST(root->Right, data);
	}
}
bool BST::Search(int data)
{
	return search_BST(Root, data);
}

void BST::Run_BST()
{
	Insert(15);
	Insert(55);
	Insert(45);
	Insert(35);
	Insert(25);

	int number;
	std::cout << "Enter the number to be searched\n";
	std::cin >> number;

	(Search(number)) ? std::cout << "Number Found \n" : std::cout << "Not Found\n";
}

int Node::GetData()
{
	return data;
}

void Node::SetData(int Data)
{
	data = Data;
}

Node* Node::GetNext()
{
	return Next;
}

void Node::SetNext(Node* next)
{
	Next = next;
}

Node* Node::Insert(Node** Head, int x)
{
	Node* temp = new Node();

	temp->SetData(x);
	temp->SetNext(*Head);

	*Head = temp;
	return *Head;
}

void Node::AppendList(Node** Head, int Data)
{
	Node* temp = new Node();

	Node* LastNode = *Head;

	temp->SetData(Data);
	temp->SetNext(nullptr);

	if (*Head == nullptr)
	{
		*Head = temp;
		return;
	}
	// else Traverse till last node.

	while (LastNode->GetNext() != nullptr)
	{
		LastNode = LastNode->GetNext();
	}
	LastNode->SetNext(temp);
	return;
}

void Node::PrintList(Node* Head)
{
	std::cout << "Data list : ";

	while (Head != nullptr)
	{
		std::cout << " " << Head->GetData();
		Head = Head->GetNext();
	}
	std::cout << "\n";
}

void Node::InsertAt(Node** Head, int x, int n)
{
	if (n == 0)
	{
		std::cout << "The Given data at 'n' cannot be assigned to null\n";
	}

	Node* temp = new Node();
	temp->SetData(x);
	if (n == 1)
	{
		temp->SetNext(nullptr);
		*Head = temp;
		return;
	}

	Node* temp2 = *Head;
	if (Head == nullptr)
	{
		std::cout << "The Given data cannot be assigned to null\n";
	}
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->GetNext();
	}

	temp->SetNext(temp2->GetNext());
	temp2->SetNext(temp);
	return;
}

void Node::DeleteNode(Node** Head, int n)
{
	Node* temp = *Head;

	if (n == 1)
	{
		*Head = temp->GetNext();
		delete temp;
		std::cout << "\nAfter Deletion of Head Node\n";
		return;
	}

	for (int i = 0; i < n - 2; i++)
	{
		temp = temp->GetNext();
	}
	Node* temp2 = temp->GetNext();
	temp->SetNext(temp2->GetNext());
	delete temp2;
	std::cout << "\nAfter Deletion of Node\n";
}

void Node::Recursion_Print(Node* Head)
{
	if (Head == nullptr)
	{
		return;
	}

	std::cout << ' ' << Head->GetData(); //comment to Do Reverse the Linked list
	Recursion_Print(Head->GetNext());
	//std::cout << ' ' << Head->GetData();//unComment to Reverse the linked List recursivly
}

int Node::LinkedList_Count(Node* Head)
{
	int count = 0;

	Node* Current = Head;
	while (Current != nullptr)
	{
		count++;
		Current = Current->GetNext();
	}
	std::cout << "\nNumber of Elements: " << count;
	return count;
}

void Node::RunLinkedList()
{
	Node* Head = nullptr;

	Insert(&Head, 6);
	Insert(&Head, 7);
	Insert(&Head, 8);
	std::cout << "after Appending and inserting\n";
	InsertAt(&Head, 18, 2);
	AppendList(&Head, 16);
	PrintList(Head);
	DeleteNode(&Head, 2);
	std::cout << "Recursive_Print DataList:\n";
	Recursion_Print(Head);
	LinkedList_Count(Head);
	delete Head;
}
