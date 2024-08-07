#include <iostream>
#include <vector>
using namespace std;

// Define the structs Workshops and Available_Workshops.
// Implement the functions initialize and CalculateMaxWorkshops

struct Workshop {
  int start_time;
  int duration;
  int end_time;
};

struct Available_Workshops {
  Workshop *WorkshopList;
  int n;
};

Available_Workshops *initialize(int *start_time, int *duration, int n) {
  Workshop *WorkshopList = new Workshop[n];
  for (int i = 0; i < n; i++) {
    WorkshopList[i].duration = duration[i];
    WorkshopList[i].start_time = start_time[i];
    WorkshopList[i].end_time =
        WorkshopList[i].duration + WorkshopList[i].start_time;
  }
  Available_Workshops *Available_Workshops_object = new Available_Workshops;
  Available_Workshops_object->WorkshopList = WorkshopList;
  Available_Workshops_object->n = n;
  return Available_Workshops_object;
}

bool overlapChecker(std::vector<Workshop> &listofWorkshops,
                    Workshop &candidate) {
  int start, end;
  for (std::size_t i = 0; i < listofWorkshops.size(); i++) {
    start = std::max(candidate.start_time, candidate.start_time);
    end = std::min(candidate.end_time, listofWorkshops[i].end_time);

    if (start < end)
      return true;
  }
  return false;
}
int CalculateMaxWorkshops(Available_Workshops *ptr) {
  int max_workshop_to_attend = 0;

  std::vector<Workshop> listofWorkshops;
  for (int i = 0; i < ptr->n; i++) {
    listofWorkshops.clear();
    Workshop mustIncluded = ptr->WorkshopList[i];

    listofWorkshops.push_back(mustIncluded);
    for (int j = 0; j < ptr->n; j++) {
      Workshop candidate = ptr->WorkshopList[j];
      if (i != j && !overlapChecker(listofWorkshops, candidate))
        listofWorkshops.push_back(candidate);
    }
    max_workshop_to_attend =
        std::max(int(listofWorkshops.size()), max_workshop_to_attend);
  }
  return max_workshop_to_attend;
}

template <typename T> void printArray(T array, std::size_t arraySize) {
  for (std::size_t i = 0; i < arraySize; i++)
    std::cout << array[i] << std::endl;
}

int main(int argc, char *argv[]) {
  //    int n; // number of workshops
  //    cin >> n;
  //    // create arrays of unknown size n
  //    int* start_time = new int[n];
  //    int* duration = new int[n];

  //    for(int i=0; i < n; i++){
  //        cin >> start_time[i];
  //    }
  //    for(int i = 0; i < n; i++){
  //        cin >> duration[i];
  //    }

  int n;
  // n=6; // number of workshops
  n = 8;
  // create arrays of unknown size n
  int *start_time = new int[n];
  int *duration = new int[n];

  int i = 0;

  for (auto v : {5, 5, 6, 3, 4, 1, 3, 2}) {
    start_time[i] = v;
    i++;
  }
  i = 0;
  for (auto v : {1, 2, 5, 1, 1, 1, 2, 1}) {
    duration[i] = v;
    i++;
  }

  //    printArray(start_time, n);
  //    printArray(duration, n);

  Available_Workshops *ptr; //=new Available_Workshops;
  ptr = initialize(start_time, duration, n);
  cout << CalculateMaxWorkshops(ptr) << endl;
  delete[] start_time;
  delete[] duration;
  delete[] ptr->WorkshopList;
  delete ptr;
  return 0;
}
