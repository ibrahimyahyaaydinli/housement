import React, {useState} from 'react';

import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  StyleSheet,
  Text,
  useColorScheme,
  View,
  TouchableOpacity,
  TextInput,
  Alert,
} from 'react-native';

import {readData} from './Database';

import IconHome from 'react-native-vector-icons/MaterialCommunityIcons';

const Login = ({navigation}) => {
  const [inputId, setInputId] = useState();
  let proId = readData('productId');

  const control = () => {
    if (inputId == proId) {
      Alert.alert(
        'Giriş Başarılı',
        'Doruca anasayfanıza yönlendiriliyorsunuz',
        [
          {
            text: 'Tamam',
            onPress: () => navigation.navigate('Main1'),
          },
        ],
      );
    } else {
      Alert.alert('Giriş Başarısız', 'Kimliği doğru girdiğinizden emin olun.', [
        {
          text: 'Anladım',
        },
      ]);
    }
  };
  return (
    <View>
      <View
        style={{
          alignItems: 'center',
          height: 120,
          justifyContent: 'space-around',
          backgroundColor: '#243A73',
          borderBottomLeftRadius: 50,
          borderBottomRightRadius: 50,
        }}>
        <Text
          style={{
            fontSize: 40,
            fontFamily: 'Questrial-Regular',
            color: 'white',
          }}>
          H O U S E M E N T
        </Text>
      </View>
      <View style={{alignItems: 'center', marginTop: 100}}>
        <TextInput
          secureTextEntry={true}
          style={{
            borderWidth: 1,
            height: 50,
            width: '80%',
            borderRadius: 10,
            backgroundColor: 'white',
            color: 'black',
          }}
          onChangeText={setInputId}
          value={inputId}
          placeholder="URUN KİMLİK ID GİRİN"
          keyboardType="numeric"
        />
      </View>
      <View style={{alignItems: 'center'}}>
        <TouchableOpacity
          style={{
            borderWidth: 1,
            height: 50,
            alignItems: 'center',
            marginTop: 25,
            justifyContent: 'space-around',
            width: '60%',
            backgroundColor: '#243A73',
          }}
          onPress={control}>
          <Text style={{fontSize: 25}}>Giriş yap</Text>
        </TouchableOpacity>
      </View>
    </View>
  );
};

export default Login;
