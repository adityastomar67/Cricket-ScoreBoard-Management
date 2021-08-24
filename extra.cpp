Score ::Score(){

};
void Score ::new_sheet()
{
    system("clear");
    cout << endl
         << setw(103) << "Welcome to New ScoreBoard" << endl;
    cout << setw(104) << "---------------------------" << endl
         << endl;
    int team_w;
    Score t1, t2;
    Score tGeneral;

    cout << "  Enter the Name of Two Playing Teams :" << endl
         << endl;
    t1.get_tName(0);
    t2.get_tName(1);
    cout << endl;
    cout << "  Enter The Number of Players for Teams : ";
    tGeneral.mPlayers(t1, t2);

    cout << endl
         << "  Enter the Number Overs, You want in Match : ";
    tGeneral.m_over();

    team_w = toss(t1.tNum, t2.tNum);
    if (toss(t1.tNum, t2.tNum))
    {
        t1.start_scoreboard(); // we can start it with tGeneral.start_scoreboadr(t1 or t2)
    }
    else
    {
        t2.start_scoreboard();
    }
}
void Score ::load_sheet()
{

}
void Score ::save_sheet()
{

}
void Score ::start_scoreboard()
{
    cout << show_tName() << " wons the Toss!!...and choses to bat" << endl;
}
void Player ::show()
{

}
void Player ::dot_ball()
{}
void Player ::add_run(int pNumber, int run)
{
    NBalls++;
    pRun[pNumber][NBalls] += run;

    score_total();
}
void Player ::wicket()
{}
void Player ::setExtra()
{
    cout << "\n\n**********************************\n";
    cout << "             Extra Run              \n";
    cout << "**********************************\n\n";
    cout << "Extra?";
    cin >> extra_run;
    //   t1.Set_Extra(extra_run);
}
void Player ::over_complete()
{

}
void Score ::m_over()
{
    int n;
    cin >> n;
    while (n > mOVER)
    {
        cout << endl
             << "Number of Overs can't be Higher than " << mOVER << "."
             << endl
             << "Enter again : ";
        cin >> n;
        cout << endl;
        cout << endl;
    }
    m_Over = n;
}
int Score ::score_total()
{
    int local_total = 0;
    for (int i = 0; i < mPLAYERS; i++)
    {
        for (int j = 0; j < mBALLS; j++)
        {
            local_total += pRun[i][j]; // Adding each Player's Score.
        }
    }
    local_total += extra_run; // Add Extra runs to local_total.

    return local_total;
}