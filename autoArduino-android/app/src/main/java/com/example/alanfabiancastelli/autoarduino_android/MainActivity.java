package com.example.alanfabiancastelli.autoarduino_android;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Set;

public class MainActivity extends AppCompatActivity {

    Button botonDispositivosBt;
    TextView textoLista;
    ListView listaDBt;

    private BluetoothAdapter myBluetooth = null;
    private Set<BluetoothDevice> dispositivosPresentes;
    public static String EXTRA_ADDRESS = "device_address";


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        botonDispositivosBt = (Button)findViewById(R.id.botonDispositivosBt);
        listaDBt = (ListView)findViewById(R.id.listaDispositivos);

        myBluetooth = BluetoothAdapter.getDefaultAdapter();

        if(myBluetooth == null)
        {
            //Show a mensag. that the device has no bluetooth adapter
            Toast.makeText(getApplicationContext(), "Dispositivo Bluetooth no activado ", Toast.LENGTH_LONG).show();

            //finish apk
            finish();
        }
        else if(!myBluetooth.isEnabled())
        {
            //Ask to the user turn the bluetooth on
            Intent turnBTon = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(turnBTon,1);
        }

        botonDispositivosBt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v)
            {
                funcionListaDispositivos();
            }
        });

    }

    private void funcionListaDispositivos()
    {
        dispositivosPresentes = myBluetooth.getBondedDevices();
        ArrayList lista = new ArrayList();

        if (dispositivosPresentes.size()>0)
        {
            for(BluetoothDevice bt :dispositivosPresentes)
            {
                lista.add(bt.getName() + "\n" + bt.getAddress()); //Get the device's name and the address
            }
        }
        else
        {
            Toast.makeText(getApplicationContext(), "No se encontaron dispositivos blutooth para conectarlo", Toast.LENGTH_LONG).show();
        }

        final ArrayAdapter adapter = new ArrayAdapter(this,android.R.layout.simple_list_item_1, lista);
        listaDBt.setAdapter(adapter);
        listaDBt.setOnItemClickListener(myListClickListener); //Method called when the device from the list is clicked

    }
    private AdapterView.OnItemClickListener myListClickListener = new AdapterView.OnItemClickListener()
    {
        public void onItemClick (AdapterView<?> av, View v, int arg2, long arg3)
        {
            // Get the device MAC address, the last 17 chars in the View
            String info = ((TextView) v).getText().toString();
            String address = info.substring(info.length() - 17);

            // Make an intent to start next activity.
            Intent i = new Intent(MainActivity.this, autoControl.class);

            //Change the activity.
            i.putExtra(EXTRA_ADDRESS, address); //this will be received at ledControl (class) Activity
            startActivity(i);
        }
    };


}
