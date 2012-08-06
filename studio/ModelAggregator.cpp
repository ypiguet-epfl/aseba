#include "ModelAggregator.h"

namespace Aseba
{
	ModelAggregator::ModelAggregator(QObject* parent) :
		QAbstractItemModel(parent)
	{

	}

	void ModelAggregator::addModel(QAbstractItemModel* model, unsigned int column)
	{
		ModelDescription description;
		description.model = model;
		description.column = column;
		models.append(description);
	}

	int ModelAggregator::columnCount(const QModelIndex &parent) const
	{
		return 1;
	}

	int ModelAggregator::rowCount(const QModelIndex & /*parent*/) const
	{
		int count = 0;
		for (ModelList::ConstIterator it = models.begin(); it != models.end(); it++)
			count += (*it).model->rowCount();
		return count;
	}

	QVariant ModelAggregator::data(const QModelIndex &index, int role) const
	{
		if (!index.isValid())
			return QVariant();

		int count = 0;
		int previousCount = 0;
		int modelID = 0;
		for (ModelList::ConstIterator it = models.begin(); it != models.end(); it++, modelID++)
		{
			previousCount = count;
			count += (*it).model->rowCount();
			if (index.row() < count)
			{
				QAbstractItemModel* thisModel = (*it).model;
				unsigned int thisColumn = (*it).column;
				QModelIndex newIndex = thisModel->index(index.row()-previousCount, thisColumn);
				return thisModel->data(newIndex, role);
			}
		}

		return QVariant();
	}

	bool ModelAggregator::hasIndex(int row, int column, const QModelIndex &parent) const
	{
		if (parent.isValid())
			return false;
		if (column >= columnCount())
			return false;
		if (row > rowCount())
			return false;
		return true;
	}

	QModelIndex ModelAggregator::index(int row, int column, const QModelIndex &parent) const
	{
		return hasIndex(row, column, parent) ? createIndex(row, column, 0) : QModelIndex();
	}

	QModelIndex ModelAggregator::parent(const QModelIndex &child) const
	{
		return QModelIndex();
	}
};
