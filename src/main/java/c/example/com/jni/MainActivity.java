package c.example.com.jni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {


private TextView id_text;
    private List<Student> studentList=new ArrayList<Student>();
    private List<People>peopleList=null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initData();

        id_text= (TextView) findViewById(R.id.id_text);
        id_text.setText(jnidemo.SayHello());
        TextView id_text2 = (TextView) findViewById(R.id.id_text2);
        jnidemo j=new jnidemo();
        peopleList=j.getPeopleInfo((ArrayList)studentList);
        if(peopleList==null)
            Toast.makeText(this, "getPeopleInfo(null)==null", Toast.LENGTH_SHORT).show();
        else
        {
            Toast.makeText(this, "getPeopleInfo(null)!=null", Toast.LENGTH_SHORT).show();
            Toast.makeText(this, "getPeopleInfo size"+peopleList.size(), Toast.LENGTH_SHORT).show();
            if(peopleList.size()>0)
            {
                Toast.makeText(this, "New People Student name"+peopleList.get(0).getStudent().getName(), Toast.LENGTH_SHORT).show();
            }
        }
//        id_text.setText();
        id_text2.setText(jnidemo.getStudentInfo().toString());
        TextView id_text3 = (TextView) findViewById(R.id.id_text3);
        id_text3.setText(j.updateStudentInfo(new Student("a",10)).getName());
    }

    private void initData() {
        studentList.add(new Student("a", 1));
        studentList.add(new Student("b", 2));
        studentList.add(new Student("c", 3));
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
