/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:59:41 by terussar          #+#    #+#             */
/*   Updated: 2024/03/29 13:53:01 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>

int main()
{
	std::cout << "------- Mandatory ----------" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "premier element pile: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "taille pile: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	
	std::cout << std::endl << "------- Other examples ----------" << std::endl;
	
	std::vector<int> myvector;
	myvector.push_back(5);
	myvector.push_back(17);
	std::cout << "premier element pile: " << myvector.back() << std::endl;
	myvector.pop_back();
	std::cout << "taille pile: " << myvector.size() << std::endl;
	myvector.push_back(3);
	myvector.push_back(5);
	myvector.push_back(737);
	//[...]
	myvector.push_back(0);
	std::vector<int>::iterator it2 = myvector.begin();
	std::vector<int>::iterator ite2 = myvector.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
	std::cout << *it2 << std::endl;
	++it2;
	}
	std::vector<int> s2(myvector);
	return 0;
}
