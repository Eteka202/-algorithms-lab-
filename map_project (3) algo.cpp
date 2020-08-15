// all header
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <random>       // random function header file
#include <string>       // c++ string header
#include <iostream>     // c++ input output
#include <queue>        // STL queue for heap data structure
#include <ctime>        // c time function for stop repetition
#include <algorithm>    // string lower case to upper case
using namespace std;
const int SIZE = 16;
string city[20] = {"gabtoli","mirpure","kolanpure", "shamoli", "dhanmondi", "farmgate", "shahabag",
                   "lalbag","bansal", "motijil", "waari", "maniknogor", "bibir_bagicha", "doniya",
                   "rayer_bag", "sodor_gath"
                  };
double weight[SIZE] [SIZE] =    // Edge weight
{
    {0.0, 6.2, 2.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 15.0},
    {6.2, 0.0, 6.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {2.2, 6.1, 0.0, 2.7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 2.7, 0.0, 4.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 4.4, 0.0, 2.9, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 2.9, 0.0, 5.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 3.0, 5.1, 0.0, 3.6, 0.0, 3.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.6, 0.0, 2.0, 6.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 3.3, 2.2, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.5, 6.2, 3.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.2, 0.0, 0.0, 4.0, 3.8, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.0, 0.0, 2.3, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.8, 2.3, 0.0, 2.6, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.6, 0.0, 2.2, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.2, 0.0, 6.3},
    {15.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.3, 0.0}
};
struct Edge
{
    int x;
    double cost;
    Edge(int _x, double _cost)    // Structure constractor
    {
        x = _x;
        cost = _cost;
    }
    bool operator < (const Edge & a) const   // operator overloading for priority queue
    {
        return cost > a.cost;
    }
};
char city_map( )
{
    system("cls");
    int flag, u, v;
    string curent, destinato;
    printf("\n\t\t\t\t\tCity map\n\n\tAvailable city:\n\n\t");
    for(int i= 0, cnt = 1; i < SIZE; i++, cnt++)   // print available city
    {
        printf("%-20s", city[i].c_str());  // -20s means that it takes  20 space for   print
        if(cnt == 4)
        {
            printf("\n\t");
            cnt = 0;
        }
    }
curent_location:
    printf("\n\tEnter your current location: ");
    cin >> curent;  // input naya replace of scanf
    transform(curent.begin(), curent.end(), curent.begin(), ::tolower); // string upper case to lower case
    flag = -1;
    for(int i = 0; i < SIZE; i++)  // linear search
    {
        if(curent == city[i])
        {
            flag = 1;
            u = i;
            break;
        }
    }
    if(flag == -1)
    {
        printf("\t%s is not available.\n\tAre your want to check available city? (Y / N) :", curent.c_str( ));
        char cc;
        cin >> cc;
        if(cc == 'Y')
        {
            goto curent_location;
        }
        else
        {
            printf("\tThank you.");
            for(int i= 0; i < (int) 1e8; i++);
            system("cls");
            return 'N';
        }
    }
destinato_city:
    printf("\tEnter Your destination: ");
    cin >> destinato;
    flag = -1;
    for(int i = 0; i < SIZE; i++)
    {
        if(destinato == city[i])
        {
            flag = 1;
            v = i;
            break;
        }
    }
    if(flag == -1)
    {
        printf("\t%s is destination city not available.\n\tAre your want to check available city? (Y / N) :", destinato.c_str( ));
        char cc;
        cin >> cc;
        if(cc == 'Y')
        {
            goto destinato_city;
        }
        else
        {
            printf("\tThank you.");
            for(int i= 0; i < (int) 1e8; i++);
            system("cls");
            return 'N';
        }
    }

    // dijkstra
    double dist[SIZE];
    int path[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        dist[i] = 10000000;
        path[i] = 0;
    }
    priority_queue<Edge> q;
    q.push(Edge(u, 0));
    path[u] = 1;
    while(!q.empty( ))
    {
        Edge uv = q.top( );
        q.pop( );
        for(int i = 0; i < SIZE; i++)
        {
            if(i != uv.x && weight[uv.x] [i] != 0.0 && dist[i] > uv.cost + weight[uv.x] [i])
            {
                path[i] = uv.x;
                dist[i] = uv.cost + weight[uv.x] [i];
                q.push(Edge(i, dist[i]));
            }
        }
    }
    if(dist[v] == 10000000)
    {
        printf("Path not found\n");
        printf("\n\tWant to return home? (Y / N)");
        char ca = getchar();
        return ca;
    }
    int p_path = v;
    int p[SIZE], p_index = 0;
    memset(p, 0, sizeof p);
    while(p_path != 0)
    {
        p[p_index++] = p_path;
        p_path = path[p_path];
    }
    printf("\tTotal distance: %lf km\n\tRoads:  ",  dist[v]);
    for(int i = p_index; i >= 0; i--)
    {
        if(i == 0)
        {
            printf("%s\n", city[p[i]].c_str( ));
        }
        else
        {
            printf("%s -> ", city[p[i]].c_str( ));
        }
    }
    printf("\n\tWant to return home? (Y / N)");
    char ca;
    cin >> ca;
    return ca;
}


char cab_book( )
{
    system("cls");
    string curent, destinato;
    int flag, u, v;
    printf("\n\t\t\t\t\tCab booking\n\n\tAvailable city:\n\n\t");
    for(int i= 0, cnt = 1; i < SIZE; i++, cnt++)
    {
        printf("%-20s", city[i].c_str());
        if(cnt == 4)
        {
            printf("\n\t");
            cnt = 0;
        }
    }
curent_location:
    printf("\n\tEnter your current location: ");
    cin >> curent;  // input  replace of scanf
    transform(curent.begin(), curent.end(), curent.begin(), ::tolower); // string upper case to lower case
    flag = -1;
    for(int i = 0; i < SIZE; i++)   // linear search
    {
        if(curent == city[i])
        {
            flag = 1;
            u = i;
            break;
        }
    }
    if(flag == -1)
    {
        printf("\t%s is not available.\n\tAre your want to check available city? (Y / N) :", curent.c_str( ));
        char cc;
        cin >> cc;
        if(cc == 'Y')
        {
            goto curent_location;
        }
        else
        {
            printf("\tThank you.");
            for(int i= 0; i < (int) 1e8; i++);
            system("cls");
            return 'N';
        }
    }
destinato_city:
    printf("\tEnter Your destination: ");
    cin >> destinato;
    flag = -1;
    for(int i = 0; i < SIZE; i++)
    {
        if(destinato == city[i])
        {
            flag = 1;
            v = i;
            break;
        }
    }
    if(flag == -1)
    {
        printf("\t%s is destinaton city not available.\n\tAre your want to check available city? (Y / N) :", destinato.c_str( ));
        char cc;
        cin >> cc;
        if(cc == 'Y')
        {
            goto destinato_city;
        }
        else
        {
            printf("\tThank you.");
            for(int i= 0; i < (int) 1e8; i++);
            system("cls");
            return 'N';
        }
    }
    // dijkstra

    double dist[SIZE];
    int path[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        dist[i] = 10000000;
        path[i] = 0;
    }
    priority_queue<Edge> q;   // heap data structure
    q.push(Edge(u, 0));  // u location v destination
    path[u] = 1;
    while(!q.empty( ))   // start dijkstra
    {
        Edge uv = q.top( );
        q.pop( );
        for(int i = 0; i < SIZE; i++)
        {
            if(i != uv.x && weight[uv.x] [i] != 0.0 && dist[i] > uv.cost + weight[uv.x] [i])
            {
                path[i] = uv.x;
                dist[i] = uv.cost + weight[uv.x] [i];
                q.push(Edge(i, dist[i]));
            }
        }
    }
    if(dist[v] == 10000000)
    {
        printf("Path not found\n");
        printf("\n\tWant to return home? (Y / N)");
        char ca;
        cin >> ca;
        return ca;
    }

    // disjoint set  path finding
    int p_path = v;
    int p[SIZE], p_index = 0;
    memset(p, 0, sizeof p);
    while(p_path != 0)
    {
        p[p_index++] = p_path;
        p_path = path[p_path];
    }

    // cab genarate
    int cab[SIZE];  // cab number store
    int CabNumber = rand( ) % 6;  // randomly cab number genarate

    if(CabNumber == 0)  // cab not available
    {
        printf("\tSorry! Cab is not available at this time.\n");
        printf("\n\tWant to return home? (Y / N)");
        char ca;
        cin >> ca;
        return ca;
    }

    memset(cab, 0, sizeof cab);
    printf("\tCab available at city:\n\n");
    printf("\tCode  %-20s Available Time(minute)\n","City name");
    for(int i = 0; i < CabNumber; i++)
    {
        cab[i] = rand() % SIZE;   // randomly city genarate
        printf("\t%-6d%-20s %.2lf\n", i, city[cab[i]].c_str(), dist[cab[i]] / 2.0);  // city location and cab location print
    }
    puts("");
    int CabCode;
    printf("\tEnter your cab code: ");
    scanf("%d", &CabCode);

    printf("\tYour cab will be available after %.2lf minute\n", dist[cab[CabCode]] / 2.0); // cab available 2 km for 1 minute
    printf("\tTotal distance: %.2lf km\n",  dist[v]); // distance
    printf("\tTotal cost: %.2lf tk\n\tRoads:  ",  dist[v] * 15);  // cost per km 15 tk

    for(int i = p_index; i >= 0; i--)  // road system print  like lcs path
    {
        if(i == 0)
        {
            printf("%s\n", city[p[i]].c_str( ));
        }
        else
        {
            printf("%s -> ", city[p[i]].c_str( ));
        }
    }
    printf("\n\tWant to return home? (Y / N)");
    char ca;
    cin >> ca;
    return ca;   // return your input
}
void home( )
{
    system("color 0E");
    printf("\033[1;31m");
    printf("\n\n\n\n\t\t\t\t\tCity map and cab\n\n\n\n\n\n\n\n\t\t\t");
    printf("\033[0m");
    for(int i = 0; i < 50; i++)    // loding page
    {
        for(int i = 0; i < (int) 5 * 1e7; i++);   // 5 * 10 ^ 7  == less than 5 second delay
        printf("-");
    }
Home:
    system("cls");
    system("color F1");
    printf("\n\t\t\t\t\tCity map and cab\n");
    printf("\n\t\t\t\t1. Book cab\t\t2.Map\n\n");
xy:
    printf("\t\t\t\tEnter your choice: ");
    int c;
    scanf("%d", &c);   // input choice
    if(c == 1)
    {
        char ac = cab_book();     // Booking cab where it is available   it return input
        if(ac == 'Y')
        {
            goto Home;
        }
    }
    else if(c == 2)
    {
        char ac = city_map();     // city map road from one place to another
        if(ac == 'Y')
        {
            goto Home;
        }
    }
    else
    {
        printf("\n\t\t\t\tPlease enter choice correctly\n");
        goto xy;
    }
}
int main()
{
    srand(time(NULL));   // rand ( ) function repetition stop
    home( );
    return 0;
}
