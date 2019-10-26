#pragma once
#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <vector>
#include <cstdint>
#include <ctime>

class Product;
class MyInfo;

// transaction of blockchain
class Order {
	friend class Block;

	std::string orderer_name;                  // �� �̸�
	static const std::string store_name;       // ���� �̸�
	static const std::string store_location;   // ���� ��ġ
	static const std::string phone_number;     // ���� ����ó
	time_t timestamp;                          // �ֹ��� �ð�
	std::string payment_method;                // ���� ����
	std::vector<Product *> product;            // ������ ��ǰ��
	std::int64_t vat;                          // �ΰ���ġ��
	std::int64_t discount;                     // ����Ʈ, ���� �� ����
	std::int64_t total_amount;                 // ��ǰ���� �� �ݾ�
	
	Order(std::string _orderer_name, std::string _payment_method, std::vector<Product *> _product, std::int64_t discount);

public:
	bool new_order(MyInfo * _myinfo, Product * _product);
	bool new_order(MyInfo * _myinfo, std::vector<Product *> _product_vector);

	void print();
	void print_detail();
	void print_hash();

	time_t get_timestamp();
	void set_timestamp();
};

#endif // !ORDER_H
